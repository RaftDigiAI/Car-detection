#ifndef TENSORFLOWVIDEOSINK_H
#define TENSORFLOWVIDEOSINK_H

#include <QObject>
#include <QQmlEngine>
#include <QVideoSink>
#include <QVideoFrame>

class TensorflowVideoSink : public QVideoSink {
  Q_OBJECT
  QML_ELEMENT
public:
  TensorflowVideoSink(QObject *parent = nullptr);
  void processFrame();
};

#endif // TENSORFLOWVIDEOSINK_H
