#include "tfmodel.h"

TFModel::TFModel() : AbstractTFModel() {
  auto pathToModel =
      AbstractTFModel::placeModel(Constants::General::modelName).toStdString();

  // Init model
  mModel = tflite::FlatBufferModel::BuildFromFile(pathToModel.c_str());
  // Build the interpreter
  tflite::InterpreterBuilder builder(*mModel, mResolver);
  auto status = builder(&mInterpreter);
  qDebug() << "TensorflowModel::TensorflowModel. Builder status ok?:"
           << (status == kTfLiteOk);
  // If set to the value -1, the number of threads used
  // will be implementation-defined and platform-dependent.
  builder.SetNumThreads(4);

  // Allocate tensors if previously state is ok
  if (status == kTfLiteOk) {
    status = mInterpreter->AllocateTensors();
    qDebug() << "TensorflowModel::TensorflowModel. Tensors allocated?:"
             << (status == kTfLiteOk);
  }

  if (status == kTfLiteOk)
    mInput = mInterpreter->typed_input_tensor<uchar>(0);
}

std::tuple<bool, int, float> TFModel::forward(const QImage &image) noexcept {
  if (mInput == nullptr) {
    qWarning() << "TensorflowModel::forward(const QImage &image)."
               << "Model input equal nullptr.";
    return {false, -1, -1};
  }

  const auto transformedImage = transform(image);
  const auto *inputImage = transformedImage.bits();

  if (inputImage == nullptr) {
    qWarning() << "TensorflowModel::forward. Image equal nullptr.";
    return {false, -1, -1};
  }

  // Function definition:
  // memcpy(void* destination, const void* source, std::size_t count);
  std::memcpy(mInput, inputImage, Constants::Model::size);

  {
    QElapsedTimer timer;
    timer.start();
    const auto status = mInterpreter->Invoke();
    qInfo() << "TensorflowModel::forward. Inference time:" << timer.elapsed()
            << "ms.";

    if (status == kTfLiteOk) {
      const auto &[classId, score] = processOutput();
      return {true, classId, score};
    }
  }

  qWarning() << "TensorflowModel::forward. Cannot make forward;";
  return {false, -1, -1};
}

bool TFModel::enableGPU() {
  mDelegate = TfLiteGpuDelegateV2Create(nullptr);
  const auto status = mInterpreter->ModifyGraphWithDelegate(mDelegate);
  if (status != kTfLiteOk) {
    qCritical()
        << "TensorflowModel::TensorflowModel. Cannot use delegate. Error:"
        << status;
    TfLiteGpuDelegateV2Delete(mDelegate);
    return false;
  }

  return true;
}

TFModel::~TFModel() { TfLiteGpuDelegateV2Delete(mDelegate); }

std::pair<int, float> TFModel::processOutput() const noexcept {
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
  // In these model countDetected cannot be more than 25.
  for (uint i = 0; itUsable && (i < countDetected); i++) {
    const auto &classId = static_cast<uchar>(detectedClasses[i]);
    const auto &score = detectedScores[i];
    const bool itDetected{detectedScores[i] >= Constants::Model::threshold};

    if (itDetected) {
      predictions.try_emplace(classId, 0);
      predictions[classId] = std::max(predictions[classId], score);
    }
  }

  qDebug() << predictions;

  return {Constants::Model::carClass, predictions[Constants::Model::carClass]};
}

const QImage TFModel::transform(const QImage &image) noexcept {
  QImage inputImage{image.scaled(Constants::Model::inputWidth,
                                 Constants::Model::inputHeight)};
  inputImage.convertTo(Constants::Model::imgFormat);
  return inputImage;
}
