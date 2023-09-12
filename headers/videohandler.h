#ifndef TESTVIDEOSINK_H
#define TESTVIDEOSINK_H

#include <QObject>
#include <QPainter>
#include <QQmlEngine>
#include <QString>
#include <QVideoFrame>
#include <QVideoSink>

#include "tensorflowmodel.h"

class VideoHandler : public QObject {
  Q_OBJECT
  QML_ELEMENT
  Q_PROPERTY(QVideoSink *videoSink READ videoSink WRITE setVideoSink NOTIFY
                 videoSinkChanged FINAL)
  Q_PROPERTY(bool itWork READ itWork WRITE setItWork NOTIFY itWorkChanged FINAL)
public:
  VideoHandler(QObject *parent = nullptr);

  /**
   * @brief videoSink
   * @return pointer on current video sink.
   */
  QVideoSink *videoSink() const;

  /**
   * @brief setVideoSink
   * @param newVideoSink
   */
  void setVideoSink(QVideoSink *newVideoSink);

  bool itWork() const;
  void setItWork(bool newItWork);

signals:
  void videoSinkChanged();
  void itWorkChanged();

private slots:
  /**
   * @brief proccesFrame
   * @param frame
   */
  void proccesFrame();

private:
  TensorflowModel mModel;

  QPointer<QVideoSink> mVideoSink;
  bool mItWork;
};

#endif // TESTVIDEOSINK_H
