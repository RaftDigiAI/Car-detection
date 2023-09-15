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
  const std::tuple<bool, int, float> forward(const QImage &image) noexcept;

private:
  QString placeModel();
  std::pair<int, float> processOutput();
  template <typename T> T *getOutput(const int &numOutput);

private:
  QPointer<QTemporaryFile> mFileModel;
  std::unique_ptr<tflite::Interpreter> mInterpreter;
  std::unique_ptr<tflite::FlatBufferModel> mModel;
  tflite::ops::builtin::BuiltinOpResolver mResolver;
  uchar *mInput;
};

template <typename T> T *TensorflowModel::getOutput(const int &numOutput) {
  return mInterpreter->typed_output_tensor<T>(numOutput);
}
