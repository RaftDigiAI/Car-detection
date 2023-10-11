#include "videohandler.h"

VideoHandler::VideoHandler(QObject *parent)
    : QObject{parent}, mVideoSink{nullptr}, mClassId{-1}, mScore{0},
      mInferenceStatus{false} {
  mModelWorker = std::make_unique<TFModelWorker>();
  mModelWorker->moveToThread(&mThread);
  mModelTimer.setInterval(Constants::General::inferenceDelayMs);

  // Connections
  connect(&mModelTimer, &QTimer::timeout, this, [&]() {
    QMetaObject::invokeMethod(
        mModelWorker.get(), "processImage", Qt::QueuedConnection,
        Q_ARG(QImage, mVideoSink->videoFrame().toImage()));
  });
  connect(mModelWorker.get(), &TFModelWorker::proccesFailed, this,
          [&]() { updateStatus(); });
  connect(mModelWorker.get(), &TFModelWorker::imageProcessed, this,
          [&](const int &classId, const double &score) {
            updateStatus(true, classId, score);
          });
  connect(&mThread, &QThread::started, mModelWorker.get(),
          &TFModelWorker::createModel);


  mThread.start();
}

VideoHandler::~VideoHandler() {
  mThread.quit();
  mThread.wait();
}

///////////////////////QML CONNECTIONS/////////////////////////////////////////

QVideoSink *VideoHandler::videoSink() const noexcept {
  return mVideoSink.get();
}

void VideoHandler::setVideoSink(QVideoSink *newVideoSink) noexcept {
  if (mVideoSink == newVideoSink)
    return;

  mVideoSink = newVideoSink;
  emit videoSinkChanged();

  mModelTimer.start();
}

bool VideoHandler::inferenceStatus() const { return mInferenceStatus; }

void VideoHandler::setInferenceStatus(bool newInferenceStatus) {
  if (mInferenceStatus == newInferenceStatus)
    return;
  mInferenceStatus = newInferenceStatus;
  emit inferenceStatusChanged();
}

float VideoHandler::score() const { return mScore; }

void VideoHandler::setScore(float newScore) {
  if (qFuzzyCompare(mScore, newScore))
    return;
  mScore = newScore;
  emit scoreChanged();
}

int VideoHandler::classId() const { return mClassId; }

void VideoHandler::setClassId(int newClassId) {
  if (mClassId == newClassId)
    return;
  mClassId = newClassId;
  emit classIdChanged();
}

///////////////////////////END QML CONNECTIONS//////////////////////////////////

void VideoHandler::processFrame() {
  if (mVideoSink.isNull()) {
    qCritical() << "VideoHandler::processFrame. Start process frame when video "
                   "sink is null.";
    return;
  }

  const QVideoFrame frame{mVideoSink->videoFrame()};
  QElapsedTimer timer;
  timer.start();
  mModelWorker->processImage(frame.toImage());
  qInfo() << "VideoHandler::processFrame. Process time:" << timer.elapsed()
          << "ms.";
}

void VideoHandler::updateStatus(const bool &inferenceStatus,
                                const int &detectedClass,
                                const double &classScore) {
  setInferenceStatus(inferenceStatus);
  setScore(classScore);
  setClassId(detectedClass);
}
