#pragma once

#include "constants.hpp"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QFileInfo>
#include <QImage>
#include <QObject>
#include <QPointer>
#include <QString>
#include <QTemporaryFile>
#include <cstdint>
#include <memory>
#include <utility>

class TensorflowModel : public QObject {
  Q_OBJECT
public:
  explicit TensorflowModel(QObject *parent = nullptr);

  /**
   * Make model forward
   * @param image Input image
   * @return Status, class id, score. Class id and score can be equal -1, if objects not detected
   * or was problems in process.
   */
  std::tuple<bool, int, float> forward(const QImage &image) noexcept;

private:
  /**
   * It loaded model from resource and place it on disk like temporary file.
   * After close application file wil be deleted.
   * @return
   */
  QString placeModel();

  /**
   * Get output from model and process it.
   * @return Num class id and it score.
   */
  std::pair<int, float> processOutput();

  /**
   * Get output from model.
   * Directly is the same like mInterpreter->typed_output_tensor<T>(numOutput);
   * @tparam T Type output parameter
   * @param numOutput Number output tensor
   * @return Pointer to selected output tensor
   */
  template <typename T> T *getOutput(const int &numOutput) noexcept;

private:
  QPointer<QTemporaryFile> mFileModel;
  std::unique_ptr<tflite::Interpreter> mInterpreter;
  std::unique_ptr<tflite::FlatBufferModel> mModel;
  tflite::ops::builtin::BuiltinOpResolver mResolver;
  uchar *mInput;
};

template <typename T> T *TensorflowModel::getOutput(const int &numOutput) noexcept{
  return mInterpreter->typed_output_tensor<T>(numOutput);
}
