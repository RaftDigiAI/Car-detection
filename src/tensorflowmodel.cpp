#include "tensorflowmodel.h"

TensorflowModel::TensorflowModel(QObject *parent) : QObject{parent} {
  auto pathToModel = placeModel().toStdString();
  //  // Init model
    mModel = tflite::FlatBufferModel::BuildFromFile(pathToModel.c_str());
  //  // Build the interpreter
    tflite::InterpreterBuilder builder(*mModel, mResolver);
    auto status = builder(&mInterpreter);
    qDebug() << "Status:" << (status == kTfLiteOk);
    mInterpreter->AllocateTensors();
}

void process() {

}

QString TensorflowModel::placeModel() {
  QFile modelFile(":/res/model2");
  mFileModel = QTemporaryFile::createNativeFile(modelFile);

  if (mFileModel == nullptr) {
    qCritical() << "Model not exist";
  }

  return mFileModel->fileName();
}
