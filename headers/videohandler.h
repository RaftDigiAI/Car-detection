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
  Q_PROPERTY(bool objectsDetected READ objectsDetected NOTIFY
                 objectsDetectedChanged FINAL)
  Q_PROPERTY(int lastInferenceMs READ lastInferenceMs NOTIFY
                 lastInferenceMsChanged FINAL)
public:
  explicit VideoHandler(QObject *parent = nullptr);
  ~VideoHandler() override;

  /**
   * @defgroup Qml functions.
   * Qml functions for set, get class members.
   * @{
   */

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

  /**
   * @brief Get the Objects Detected object
   * @return `true` if any objects detected, otherwise `false`
   */
  bool objectsDetected() const;

  /**
   * @brief Get the last inference time.
   * @return qint64 last inference model time.
   */
  qint64 lastInferenceMs() const;

  /** @} */

signals:
  void videoSinkChanged();

  void scoreChanged();

  void carDetectedChanged();

  void objectsDetectedChanged();

  void lastInferenceMsChanged();

private slots:
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

  qint64 mLastInferenceMs{0};
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

  /**
   * @brief Set the Last Inference Ms object
   * @param newLastInferenceMs new last inference model time.
   */
  void setLastInferenceMs(qint64 newLastInferenceMs);

  /**
   * @brief Set the Objects Detected object
   * @param newObjectsDetected new status detected objects. 
   */
  void setObjectsDetected(bool newObjectsDetected);
};
