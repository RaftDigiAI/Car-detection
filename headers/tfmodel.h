#pragma once

#include "abstractobjectdetectionmodel.h"
#include "constants/general.hpp"
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
  ~TFModel() override;

  /**
   * Performs the forward pass of the TFModel using the given QImage.
   * @param image The input image to be processed by the model.
   * @return A std::map<int, float> containing the model's output.
   */
  std::map<int, float> forward(const QImage &image) noexcept override;

  /**
   * Enables GPU for the TFModel.
   * @return true if GPU is enabled successfully, false otherwise
   */
  bool enableGPU() noexcept override;

private:
  std::unique_ptr<tflite::Interpreter> mInterpreter;
  std::unique_ptr<tflite::FlatBufferModel> mModel;
  tflite::ops::builtin::BuiltinOpResolver mResolver;
  TfLiteDelegate *mDelegate;
  uchar *mInput;

  /**
   * Get output from model.
   * Directly is the same like mInterpreter->typed_output_tensor<T>(numOutput);
   * @tparam T Type output parameter
   * @param numOutput Number output tensor
   * @return Pointer to selected output tensor
   */
  template <typename T> T *getOutput(const int &numOutput) const noexcept;

  /**
   * Retrieves the predictions from the model output.
   * @return A map of predicted classes and their max confidence scores.
   * If no predictions were made, an empty map is returned
   * If on image detected few objects of the same class,
   * then only the max score from it will be returned
   */
  std::map<int, float> processOutput() const noexcept;

  /**
   * Transforms the given image for using in Tensorflow model.
   * @param image The input image to be transformed.
   * @return The transformed image.
   * @throws None
   */
  QImage transform(const QImage &image) const noexcept;
};

template <typename T>
T *TFModel::getOutput(const int &numOutput) const noexcept {
  return mInterpreter->typed_output_tensor<T>(numOutput);
}
