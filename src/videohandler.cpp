#include "videohandler.h"

VideoHandler::VideoHandler(QObject *parent)
    : QObject{parent}, mVideoSink{nullptr}, mClassId{-1}, mScore{0},
      mInferenceStatus{false} {
  mModelTimer.setInterval(Constants::General::inferenceDelayMs);
  connect(&mModelTimer, &QTimer::timeout, this, &VideoHandler::processFrame);
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

  const QVideoFrame frame = mVideoSink->videoFrame();

  QElapsedTimer timer;
  timer.start();
  processImage(frame.toImage());
  qInfo() << "VideoHandler::processFrame. Process time:" << timer.elapsed()
          << "ms.";
}

void VideoHandler::processImage(const QImage &image) noexcept {
  if (image.isNull()) {
    qDebug() << "VideoHandler::processImage. Image not valid.";
    return;
  }

  // Process results.
  const auto &[status, classId, score] = mModel.forward(image);
  setClassId(classId);
  setScore(score);
  setInferenceStatus(status);
}
