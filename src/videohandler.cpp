#include "videohandler.h"

VideoHandler::VideoHandler(QObject *parent)
    : QObject(parent), mItWork(false), mVideoSink(nullptr) {}

QVideoSink *VideoHandler::videoSink() const { return mVideoSink.get(); }

void VideoHandler::setVideoSink(QVideoSink *newVideoSink) {
  if (mVideoSink == newVideoSink)
    return;
  mVideoSink = newVideoSink;

  connect(this->mVideoSink, &QVideoSink::videoFrameChanged, this,
          &VideoHandler::proccesFrame);

  emit videoSinkChanged();
}

void VideoHandler::proccesFrame() {
  QVideoFrame frame = mVideoSink->videoFrame();
  frame.map(QVideoFrame::ReadOnly);
  // Section for working with image.
  QImage image{frame.toImage()};
  mItWork = image.isNull() ? false : true;
  emit itWorkChanged();
  //
  frame.unmap();
  mVideoSink->setVideoFrame(frame);
}

bool VideoHandler::itWork() const { return mItWork; }

void VideoHandler::setItWork(bool newItWork) {
  if (mItWork == newItWork)
    return;
  mItWork = newItWork;
  emit itWorkChanged();
}
