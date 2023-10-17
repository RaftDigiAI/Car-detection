#pragma once

#include <QDebug>
#include <QFile>
#include <QObject>

class AbstractObjectDetectionModel {
public:
  virtual ~AbstractObjectDetectionModel(){};

  /**
   * Make model forward
   * @param image Input image
   * @return Status, class id, score. Class id and score can be equal -1, if
   * objects not detected or was problems in process.
   */
  virtual std::map<int, float> forward(const QImage &image) = 0;

  /**
   * Enables GPU for the TensorflowModel.
   * @return true if the GPU is successfully enabled, false otherwise
   * @throws ErrorType if there is an error enabling the GPU
   */
  virtual bool enableGPU() = 0;

protected:
  /**
   * It loaded model from resource and place it on disk like temporary file.
   * After close application file will be deleted.
   * @return path to model
   */
  QString placeModel(const QString &modelName);
};
