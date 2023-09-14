#include "videohandler.h"

VideoHandler::VideoHandler(QObject *parent)
    : QObject{parent}, mIsValid{false}, mVideoSink{nullptr},
      mObjectOnFrame{false} {}

QVideoSink *VideoHandler::videoSink() const noexcept {
  return mVideoSink.get();
}

void VideoHandler::setVideoSink(QVideoSink *newVideoSink) noexcept {
  if (mVideoSink == newVideoSink)
    return;

  mVideoSink = newVideoSink;
  // Need disconnect?
  connect(this->mVideoSink, &QVideoSink::videoFrameChanged, this,
          &VideoHandler::processFrame);

  emit videoSinkChanged();
}

void VideoHandler::processFrame() {
  QVideoFrame frame = mVideoSink->videoFrame();
  //  mIsValid = frame.isValid() ? true : false;

  //  if (!mIsValid) {
  //    qWarning() << "Class: VideoHandler, func: processFrame. Not valid
  //    frame."; return;
  //  }

  // auto mapStatus = frame.map(QVideoFrame::ReadOnly);
  //  if (!mapStatus) {
  //    qWarning() << "Class: VideoHandler, func: processFrame. Cannot map
  //    frame."; return;
  //  }

  processImage(frame.toImage());
  //  frame.unmap();

  mVideoSink->setVideoFrame(frame);
}

void VideoHandler::processImage(const QImage &image) noexcept {
  if (image.isNull()) {
    qDebug() << "Image not valid";
    return;
  }

  // Some transform.
  qDebug() << "start scale";
  QImage inputImage{image.scaled(Constants::Model::input_width,
                                 Constants::Model::input_height)};
  // Pass image to model.

  qDebug() << "end scale";
  auto [forwardPass, objectOnFrame] = mModel.forward(inputImage);
  mInferenceCorrect = forwardPass;
  mObjectOnFrame = objectOnFrame;
  emit inferenceCorrectChanged();
  emit objectOnFrameChanged();
}

bool VideoHandler::inferenceCorrect() const { return mInferenceCorrect; }

void VideoHandler::setInferenceCorrect(bool newInferenceCorrect) {
  if (mInferenceCorrect == newInferenceCorrect)
    return;
  mInferenceCorrect = newInferenceCorrect;
  emit inferenceCorrectChanged();
}

bool VideoHandler::objectOnFrame() const { return mObjectOnFrame; }

void VideoHandler::setObjectOnFrame(bool newObjectOnFrame) {
  if (mObjectOnFrame == newObjectOnFrame)
    return;
  mObjectOnFrame = newObjectOnFrame;
  emit objectOnFrameChanged();
}

bool VideoHandler::isValid() const noexcept { return mIsValid; }

void VideoHandler::setIsValid(bool newIsValid) noexcept {
  if (mIsValid == newIsValid)
    return;
  mIsValid = newIsValid;
  emit isValidChanged();
}
