#pragma once

#include "tensorflowmodel.h"
#include <QObject>
#include <QPainter>
#include <QQmlEngine>
#include <QString>
#include <QTimer>
#include <QVideoFrame>
#include <QVideoSink>

class VideoHandler : public QObject {
  Q_OBJECT
  QML_ELEMENT

  Q_PROPERTY(QVideoSink *videoSink READ videoSink WRITE setVideoSink NOTIFY
                 videoSinkChanged FINAL)

  Q_PROPERTY(
      bool isValid READ isValid WRITE setIsValid NOTIFY isValidChanged FINAL)

  Q_PROPERTY(bool inferenceCorrect READ inferenceCorrect WRITE
                 setInferenceCorrect NOTIFY inferenceCorrectChanged FINAL)

  Q_PROPERTY(
      int classId READ classId WRITE setClassId NOTIFY classIdChanged FINAL)
  Q_PROPERTY(float score READ score WRITE setScore NOTIFY scoreChanged FINAL)

public:
  VideoHandler(QObject *parent = nullptr);

  QVideoSink *videoSink() const noexcept;
  void setVideoSink(QVideoSink *newVideoSink) noexcept;

  bool isValid() const noexcept;
  void setIsValid(bool newIsValid) noexcept;

  bool inferenceCorrect() const;
  void setInferenceCorrect(bool newInferenceCorrect);

  int classId() const;
  void setClassId(int newClassId);

  float score() const;
  void setScore(float newScore);

signals:
  void videoSinkChanged();

  void isValidChanged();

  void objectOnFrameChanged();

  void inferenceCorrectChanged();

  void classIdChanged();

  void scoreChanged();

private slots:
  /**
   * @brief proccesFrame
   * @param frame
   */
  void processFrame();

private:
  void processImage(const QImage &image) noexcept;

private:
  QTimer mTimer;

  TensorflowModel mModel;
  bool mInferenceCorrect;

  int mClassId;
  float mScore;

  QPointer<QVideoSink> mVideoSink;
  bool mIsValid;
};
