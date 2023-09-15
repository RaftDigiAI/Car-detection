#include "videohandler.h"

VideoHandler::VideoHandler(QObject *parent)
    : QObject{parent}, mIsValid{false}, mVideoSink{nullptr}, mClassId{-1},
      mScore{0}, mInferenceCorrect{false} {
  mTimer.setInterval(Constants::General::inferenceDelayMs);
  connect(&mTimer, &QTimer::timeout, this, &VideoHandler::processFrame);
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

  mTimer.start();
}

bool VideoHandler::inferenceCorrect() const { return mInferenceCorrect; }

void VideoHandler::setInferenceCorrect(bool newInferenceCorrect) {
  if (mInferenceCorrect == newInferenceCorrect)
    return;
  mInferenceCorrect = newInferenceCorrect;
  emit inferenceCorrectChanged();
}

bool VideoHandler::isValid() const noexcept { return mIsValid; }

void VideoHandler::setIsValid(bool newIsValid) noexcept {
  if (mIsValid == newIsValid)
    return;
  mIsValid = newIsValid;
  emit isValidChanged();
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
  QVideoFrame frame = mVideoSink->videoFrame();

  QElapsedTimer timer;
  timer.start();
  processImage(frame.toImage());
  qDebug() << "VideoHandler::processFrame. Process time:" << timer.elapsed()
           << "ms.";

  mVideoSink->setVideoFrame(frame);
}

void VideoHandler::processImage(const QImage &image) noexcept {
  if (image.isNull()) {
    qDebug() << "VideoHandler::processImage. Image not valid.";
    return;
  }
  QElapsedTimer timer;
  timer.start();
  // Transformation section.
  QImage inputImage{image.scaled(Constants::Model::inputWidth,
                                 Constants::Model::inputHeight)};
  inputImage.convertTo(QImage::Format_RGB888);
  // Pass image to model.
  qDebug() << "VideoHandler::processImage. Resize time:" << timer.elapsed();
  // Process results.
  const auto [status, classId, score] = mModel.forward(inputImage);
  setClassId(classId);
  setScore(score);
  setInferenceCorrect(status);
}
