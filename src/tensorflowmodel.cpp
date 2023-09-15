#include "tensorflowmodel.h"

TensorflowModel::TensorflowModel(QObject *parent) : QObject{parent} {
  auto pathToModel = placeModel().toStdString();
  // Init model
  mModel = tflite::FlatBufferModel::BuildFromFile(pathToModel.c_str());
  // Build the interpreter
  tflite::InterpreterBuilder builder(*mModel, mResolver);
  auto status = builder(&mInterpreter);
  qDebug() << "TensorflowModel::TensorflowModel. Builder status ok?:"
           << (status == kTfLiteOk);
  // Allocate tensors
  if (status == kTfLiteOk) {
    status = mInterpreter->AllocateTensors();
    qDebug() << "TensorflowModel::TensorflowModel. Tensors allocated?:"
             << (status == kTfLiteOk);
  }

  if (status == kTfLiteOk)
    mInput = mInterpreter->typed_input_tensor<uchar>(0);
}

std::tuple<bool, int, float>
TensorflowModel::forward(const QImage &image) noexcept {
  QElapsedTimer timer;

  if (mInput == nullptr) {
    qWarning() << "TensorflowModel::forward(const QImage &image)."
               << "Model input equal nullptr.";
    return {false, -1, -1};
  }

  qDebug() << "TensorflowModel::forward. Start forward: ";
  const auto *inputImage = image.bits();

  if (inputImage == nullptr) {
    qWarning() << "TensorflowModel::forward. Image equal nullptr.";
    return {false, -1, -1};
  }

  timer.start();
  // Function definition:
  // memcpy(void* destination, const void* source, std::size_t count);
  std::memcpy(mInput, inputImage, Constants::Model::size);
  qDebug() << "TensorflowModel::forward. Copy time:" << timer.nsecsElapsed()
           << "ns.";

  timer.restart();
  const auto status = mInterpreter->Invoke();
  qDebug() << "TensorflowModel::forward. Inference time:" << timer.elapsed()
           << "ms.";

  if (status == kTfLiteOk) {
    const auto &[classId, score] = processOutput();
    return {true, classId, score};
  }

  qWarning() << "TensorflowModel::forward. Cannot make forward;";
  return {false, -1, -1};
}

QString TensorflowModel::placeModel() {
  QFile modelFile(Constants::General::modelName);
  mFileModel = QTemporaryFile::createNativeFile(modelFile);

  if (mFileModel == nullptr) {
    qCritical() << "TensorflowModel::placeModel. Model not exist.";
    return {};
  }

  qDebug() << "TensorflowModel::placeModel. Try load:"
           << mFileModel->fileName();
  return mFileModel->fileName();
}

std::pair<int, float> TensorflowModel::processOutput() {
  // Model output:
  // detection_boxes: Bounding box for each detection.
  // detection_classes: Object class for each detection.
  // detection_scores: Confidence scores for each detection.
  // num_detections: Total number of detections.
  const uint countDetected{static_cast<uint>(*getOutput<float>(3))};
  const auto detectedClasses{getOutput<float>(1)};
  const auto detectedScores{getOutput<float>(2)};

  bool itUsable{detectedClasses != nullptr};
  itUsable &= detectedScores != nullptr;

  std::map<int, float> predictions{{Constants::Model::carClass, 0}};
  //  std::pair<int, float> maxPredictions{0, 0};

  for (uint i = 0; itUsable && (i < countDetected); i++) {
    const auto &classId = static_cast<uchar>(detectedClasses[i]);
    const auto &score = detectedScores[i];
    const bool itDetected{detectedScores[i] >= Constants::Model::threshold};

    if (itDetected) {
      predictions.try_emplace(classId, 0);
      predictions[classId] = std::max(predictions[classId], score);

      //      if (maxPredictions.second < predictions[classId])
      //        maxPredictions = {classId, predictions[classId]};
    }
  }

  qDebug() << predictions;

  std::pair<int, float> result = {Constants::Model::carClass,
                                  predictions[Constants::Model::carClass]};
  return result;
}
