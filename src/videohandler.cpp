#include "videohandler.h"

VideoHandler::VideoHandler(QObject *parent) : QObject{parent} {
  mModelWorker = std::make_unique<TFModelWorker>();
  mModelWorker->moveToThread(&mThread);
  mModelTimer.setInterval(constants::general::inferenceDelayMs);

  // Connections
  connect(mModelWorker.get(), &TFModelWorker::imageProcessed, this,
          &VideoHandler::updateStatus);
  connect(&mThread, &QThread::started, mModelWorker.get(),
          &TFModelWorker::createModel);
  connect(&mModelTimer, &QTimer::timeout, this, [this]() {
    QMetaObject::invokeMethod(
        mModelWorker.get(), "processImage", Qt::QueuedConnection,
        Q_ARG(QImage, mVideoSink->videoFrame().toImage()));
  });

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

double VideoHandler::score() const { return mScore; }

void VideoHandler::setScore(double newScore) {
  if (qFuzzyCompare(mScore, newScore))
    return;
  mScore = newScore;
  emit scoreChanged();
}

bool VideoHandler::carDetected() const { return mCarDetected; }

void VideoHandler::setCarDetected(bool newCarDetected) {
  if (mCarDetected == newCarDetected)
    return;
  mCarDetected = newCarDetected;
  emit carDetectedChanged();
}

bool VideoHandler::getObjectsDetected() const
{
  return mObjectsDetected;
}

void VideoHandler::setObjectsDetected(bool newObjectsDetected)
{
  if (mObjectsDetected == newObjectsDetected)
    return;
  mObjectsDetected = newObjectsDetected;
  emit objectsDetectedChanged();
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

void VideoHandler::updateStatus(const std::map<int, double> &predictions) {
  const int carClass{constants::model::carClass};
  const bool objectDetected{!predictions.empty()};
  const bool carDetected = predictions.find(carClass) != predictions.end();
  const auto score = carDetected ? predictions.at(carClass) : 0.0;

  setObjectsDetected(objectDetected);
  setScore(score);
  setCarDetected(carDetected && score > 0.5);
}


