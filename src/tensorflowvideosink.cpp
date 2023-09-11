#include "tensorflowvideosink.h"

TensorflowVideoSink::TensorflowVideoSink(QObject *parent) : QVideoSink(parent) {
  connect(this, &QVideoSink::videoFrameChanged, this,
          &TensorflowVideoSink::processFrame);
}

void TensorflowVideoSink::processFrame() {
  QVideoFrame frame = this->videoFrame();
  this->setVideoFrame(frame);
}
