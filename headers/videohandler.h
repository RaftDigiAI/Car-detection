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
  Q_PROPERTY(float score READ score NOTIFY scoreChanged FINAL)
  Q_PROPERTY(bool carDetected READ carDetected NOTIFY carDetectedChanged FINAL)
  Q_PROPERTY(bool objectsDetected READ getObjectsDetected NOTIFY
                 objectsDetectedChanged FINAL)

public:
  explicit VideoHandler(QObject *parent = nullptr);
  ~VideoHandler() override;

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
   * @return Score detected class
   */
  double score() const;

  /**
   * @brief carDetected.
   * @return `true` if detected car on frame, otherwise `false`.
   */
  bool carDetected() const;

  bool getObjectsDetected() const;
  void setObjectsDetected(bool newObjectsDetected);

signals:
  void videoSinkChanged();

  void scoreChanged();

  void carDetectedChanged();

  void objectsDetectedChanged();

private slots:
  /**
   * Get current frame and push it to the model.
   */
  void processFrame();

  /**
   * Updates the status of the video handler.
   * @param predictions. Predictions from tf model. Key is detected class, value
   * is score
   */
  void updateStatus(const std::map<int, double> &predictions);

private:
  QTimer mModelTimer;
  QThread mThread;
  std::unique_ptr<TFModelWorker> mModelWorker{nullptr};

  double mScore{0};
  bool mCarDetected;
  bool mObjectsDetected{false};

  QPointer<QVideoSink> mVideoSink{nullptr};

  /**
   * Set score detected class and emit signal if it was changed.
   * Signal: scoreChanged
   * @param newScore
   */
  void setScore(double newScore);

  /**
   * @brief setCarDetected
   * @param newCarDetected. Set status detected car or not.
   */
  void setCarDetected(bool newCarDetected);
};
