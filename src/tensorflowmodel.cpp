#include "tensorflowmodel.h"

TensorflowModel::TensorflowModel(QObject *parent) : QObject{parent} {
  auto pathToModel = placeModel().toStdString();
  //  // Init model
  mModel = tflite::FlatBufferModel::BuildFromFile(pathToModel.c_str());
  //  // Build the interpreter
  tflite::InterpreterBuilder builder(*mModel, mResolver);
  auto status = builder(&mInterpreter);
  qDebug() << "Builder status ok?:" << (status == kTfLiteOk);
  // Allocate tensors
  status = mInterpreter->AllocateTensors();
  qDebug() << "Tensors allocated?:" << (status == kTfLiteOk);

  mInput = mInterpreter->typed_input_tensor<uchar>(0);
  assert(mInput != nullptr);
}

std::pair<bool, bool> TensorflowModel::forward(const QImage &image) noexcept {
  qDebug() << "Start forward";
//  auto *inputImage = (uint8_t*)image.bits();
  auto *inputImage = image.bits();

  if (inputImage == nullptr) {
    qDebug() << "Image equal nullptr";
    return {false, false};
  }

  std::copy(inputImage, inputImage + Constants::Model::size, mInput);

  auto status = mInterpreter->Invoke();
  bool objectDetect{false};
  return {status == kTfLiteOk, objectDetect};
}

void process() {}

QString TensorflowModel::placeModel() {
  QFile modelFile(":/res/model2");
  mFileModel = QTemporaryFile::createNativeFile(modelFile);

  if (mFileModel == nullptr) {
    qCritical() << "Model not exist";
  }

  return mFileModel->fileName();
}
