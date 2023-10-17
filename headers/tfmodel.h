#pragma once

#include "abstractobjectdetectionmodel.h"
#include "constants/model.hpp"
#include <QDebug>
#include <QElapsedTimer>
#include <QFileInfo>
#include <QImage>
#include <QObject>
#include <QPointer>
#include <QString>
#include <QTemporaryFile>
#include <memory>
#include <tensorflow/lite/delegates/gpu/delegate.h>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <utility>

class TFModel : public AbstractObjectDetectionModel {
public:
  explicit TFModel(QString modelName);

  /**
   * Make model forward
   * @param image Input image
   * @return Status, class id, score. Class id and score can be equal -1, if
   * objects not detected or was problems in process.
   */
  std::map<int, float> forward(const QImage &image) noexcept override;

  /**
 * Enables GPU for the TFModel.
 *
 * @return true if GPU is enabled successfully, false otherwise
 */
  bool enableGPU() override;

  ~TFModel() override;

private:
  /**
   * Get output from model.
   * Directly is the same like mInterpreter->typed_output_tensor<T>(numOutput);
   * @tparam T Type output parameter
   * @param numOutput Number output tensor
   * @return Pointer to selected output tensor
   */
  template <typename T> const T *getOutput(const int &numOutput) const noexcept;

  /**
   * Processes the output of the Tensorflow model.
   * @return A pair containing the class ID of the detected car and the
   * confidence score.
   * @throws None
   */
  std::map<int, float> processOutput() const noexcept;

  /**
   * Transforms the given image for using in Tensorflow model.
   * @param image The input image to be transformed.
   * @return The transformed image.
   * @throws None
   */
  QImage transform(const QImage &image) const noexcept;

  std::unique_ptr<tflite::Interpreter> mInterpreter;
  std::unique_ptr<tflite::FlatBufferModel> mModel;
  tflite::ops::builtin::BuiltinOpResolver mResolver;
  TfLiteDelegate *mDelegate;
  uchar *mInput;
};

template <typename T>
const T *TFModel::getOutput(const int &numOutput) const noexcept {
  return mInterpreter->typed_output_tensor<T>(numOutput);
}
