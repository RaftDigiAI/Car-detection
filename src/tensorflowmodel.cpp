#include "tensorflowmodel.h"

TensorflowModel::TensorflowModel(QObject *parent) : QObject{parent} {
  auto pathToModel = placeModel().toStdString();
  //  // Init model
  //  mModel = tflite::FlatBufferModel::BuildFromFile(pathToModel.c_str());
  //  // Build the interpreter
  //  tflite::InterpreterBuilder(*mModel, mResolver)(&mInterpreter);
  std::unique_ptr<tflite::FlatBufferModel> m_model;
  tflite::ops::builtin::BuiltinOpResolver resolver;
  std::unique_ptr<tflite::Interpreter> interpreter;
  auto error_reporter = tflite::DefaultErrorReporter();
  m_model = tflite::FlatBufferModel::BuildFromFile(pathToModel.c_str(),
                                                   error_reporter);
  tflite::InterpreterBuilder builder(*m_model, resolver);
  auto t = &interpreter;
  TfLiteStatus tatus = builder(&interpreter);
  interpreter->AllocateTensors();
}

QString TensorflowModel::placeModel() {
  QFile modelFile(":/res/model");
  mFileModel = QTemporaryFile::createNativeFile(modelFile);

  if (mFileModel == nullptr) {
    qCritical() << "Model not exist";
  }

  return mFileModel->fileName();
}
