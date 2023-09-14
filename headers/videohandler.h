#pragma once

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

  Q_PROPERTY(
            bool isValid READ isValid WRITE setIsValid NOTIFY isValidChanged FINAL)

  Q_PROPERTY(bool objectOnFrame READ objectOnFrame WRITE setObjectOnFrame NOTIFY
                 objectOnFrameChanged FINAL)

  Q_PROPERTY(bool inferenceCorrect READ inferenceCorrect WRITE
                 setInferenceCorrect NOTIFY inferenceCorrectChanged FINAL)
public:
  VideoHandler(QObject *parent = nullptr);

  QVideoSink *videoSink() const noexcept;
  void setVideoSink(QVideoSink *newVideoSink) noexcept;

  bool isValid() const noexcept;
  void setIsValid(bool newIsValid) noexcept;

  bool objectOnFrame() const;
  void setObjectOnFrame(bool newObjectOnFrame);

  bool inferenceCorrect() const;
  void setInferenceCorrect(bool newInferenceCorrect);

signals:
  void videoSinkChanged();
  void isValidChanged();

  void objectOnFrameChanged();

  void inferenceCorrectChanged();

private slots:
  /**
   * @brief proccesFrame
   * @param frame
   */
  void processFrame();

private:
  void processImage(const QImage &image) noexcept;

private:
  TensorflowModel mModel;
  bool mObjectOnFrame;
  bool mInferenceCorrect;

  QPointer<QVideoSink> mVideoSink;
  bool mIsValid;
};
