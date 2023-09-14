#pragma once

#include "constants.hpp"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include <QDebug>
#include <QFileInfo>
#include <QImage>
#include <QObject>
#include <QPointer>
#include <QString>
#include <QTemporaryFile>
#include <memory>
#include <utility>
#include <cstdint>

class TensorflowModel : public QObject {
  Q_OBJECT
public:
  explicit TensorflowModel(QObject *parent = nullptr);
  std::pair<bool, bool> forward(const QImage &image) noexcept;

private:
  QString placeModel();

private:
  QPointer<QTemporaryFile> mFileModel;
  std::unique_ptr<tflite::Interpreter> mInterpreter;
  std::unique_ptr<tflite::FlatBufferModel> mModel;
  tflite::ops::builtin::BuiltinOpResolver mResolver;
  uchar *mInput;
};
