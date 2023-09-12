#ifndef TENSORFLOWMODEL_H
#define TENSORFLOWMODEL_H

#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include <QDebug>
#include <QFileInfo>
#include <QObject>
#include <QPointer>
#include <QString>
#include <QTemporaryFile>
#include <utility>

class TensorflowModel : public QObject {
  Q_OBJECT
public:
  explicit TensorflowModel(QObject *parent = nullptr);
  QString placeModel();

private:
  QPointer<QTemporaryFile> mFileModel;
  std::unique_ptr<tflite::Interpreter> mInterpreter;
  std::unique_ptr<tflite::FlatBufferModel> mModel;
  tflite::ops::builtin::BuiltinOpResolver mResolver;
};

#endif // TENSORFLOWMODEL_H
