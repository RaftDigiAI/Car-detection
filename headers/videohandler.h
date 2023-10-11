#pragma once

#include "tfmodelworker.h"
#include <QObject>
#include <QPainter>
#include <QQmlEngine>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QVideoFrame>
#include <QVideoSink>

class VideoHandler : public QObject {
  Q_OBJECT
  QML_ELEMENT

  Q_PROPERTY(QVideoSink *videoSink READ videoSink WRITE setVideoSink NOTIFY
                 videoSinkChanged FINAL)
  Q_PROPERTY(bool inferenceStatus READ inferenceStatus NOTIFY
                 inferenceStatusChanged FINAL)
  Q_PROPERTY(int classId READ classId NOTIFY classIdChanged FINAL)
  Q_PROPERTY(float score READ score NOTIFY scoreChanged FINAL)

public:
  explicit VideoHandler(QObject *parent = nullptr);
  ~VideoHandler();

  /**
   * Get pointer to current video sink.
   * @return Pointer to current video sink.
   */
  QVideoSink *videoSink() const noexcept;

  /**
   * Set new video sink.
   * @param newVideoSink New video sink.
   */
  void setVideoSink(QVideoSink *newVideoSink) noexcept;

  /**
   * Return current status of inference
   * @return Field `inferenceStatus`. Equal `true` if we don't have any problems
   * with model and we can made inference. Otherwise `false`.
   */
  bool inferenceStatus() const;

  /**
   * @return Class id that was detected
   */
  int classId() const;

  /**
   * @return Score detected class
   */
  float score() const;



signals:
  void videoSinkChanged();

  void inferenceStatusChanged();

  void classIdChanged();

  void scoreChanged();

private slots:
  /**
   * Get current frame and push it to the model.
   */
  void processFrame();

  /**
 * Updates the status of the video handler.
 *
 * @param inferenceStatus the new inference status
 * @param detectedClass the detected class
 * @param classScore the score of the detected class
 */
  void updateStatus(const bool &inferenceStatus = false,
                    const int &detectedClass = -1,
                    const double &classScore = 0);

private:
  /**
   * Set current inference status and emit signal if it was changed.
   * Signal: inferenceStatusChanged
   * @param newInferenceStatus
   */
  void setInferenceStatus(bool newInferenceStatus);

  /**
   * Set detected class id and emit signal if it was changed.
   * Signal: classIdChanged
   * @param newClassId
   */
  void setClassId(int newClassId);

  /**
   * Set score detected class and emit signal if it was changed.
   * Signal: scoreChanged
   * @param newScore
   */
  void setScore(float newScore);

private:
  QTimer mModelTimer;
  std::unique_ptr<TFModelWorker> mModelWorker;
  QThread mThread;

  bool mInferenceStatus;
  int mClassId;
  float mScore;

  QPointer<QVideoSink> mVideoSink;
};
