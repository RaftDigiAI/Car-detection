#include "tfmodel.h"

TFModel::TFModel(QString modelName) : AbstractObjectDetectionModel() {
  auto pathToModel =
      AbstractObjectDetectionModel::placeModel(modelName).toStdString();

  // Init model
  mModel = tflite::FlatBufferModel::BuildFromFile(pathToModel.c_str());
  // Build the interpreter
  tflite::InterpreterBuilder builder(*mModel, mResolver);
  auto status = builder(&mInterpreter);
  qDebug() << "TensorflowModel::TensorflowModel. Builder status ok?:"
           << (status == kTfLiteOk);
  // If set to the value -1, the number of threads used
  // will be implementation-defined and platform-dependent.
  builder.SetNumThreads(-1);

  // Allocate tensors if previously state is ok
  if (status == kTfLiteOk) {
    status = mInterpreter->AllocateTensors();
    qDebug() << "TensorflowModel::TensorflowModel. Tensors allocated?:"
             << (status == kTfLiteOk);
  }

  if (status == kTfLiteOk)
    mInput = mInterpreter->typed_input_tensor<uchar>(0);
}

std::map<int, float> TFModel::forward(const QImage &image) noexcept {
  if (mInput == nullptr) {
    qWarning() << "TensorflowModel::forward(const QImage &image)."
               << "Model input equal nullptr.";
    return {};
  }

  const auto transformedImage = transform(image);
  const auto *inputImage = transformedImage.bits();

  if (inputImage == nullptr) {
    qWarning() << "TensorflowModel::forward. Image equal nullptr.";
    return {};
  }

  std::memcpy(mInput, inputImage, constants::model::size);

  QElapsedTimer timer;
  timer.start();
  const auto status = mInterpreter->Invoke();
  qInfo() << "TensorflowModel::forward. Inference time:" << timer.elapsed()
          << "ms.";

  if (status == kTfLiteOk)
    return processOutput();

  qWarning() << "TensorflowModel::forward. Cannot make forward;";
  return {};
}

bool TFModel::enableGPU() {
  mDelegate = TfLiteGpuDelegateV2Create(nullptr);
  if (const auto status = mInterpreter->ModifyGraphWithDelegate(mDelegate);
      status != kTfLiteOk) {
    qCritical()
        << "TensorflowModel::TensorflowModel. Cannot use delegate. Error:"
        << status;
    TfLiteGpuDelegateV2Delete(mDelegate);
    return false;
  }

  return true;
}

TFModel::~TFModel() { TfLiteGpuDelegateV2Delete(mDelegate); }

/**
 * Retrieves the predictions from the model output.
 * @return A map of predicted classes and their max confidence scores.
 * If no predictions were made, an empty map is returned
 * If on image detected few objects of the same class,
 * then only the max score from it will be returned
 */
std::map<int, float> TFModel::processOutput() const noexcept {
  // Model output:
  // detection_boxes: Bounding box for each detection.
  // detection_classes: Object class for each detection.
  // detection_scores: Confidence scores for each detection.
  // num_detections: Total number of detections.

  // Get the total number of detected objects
  const int countDetected{static_cast<int>(std::floor(*getOutput<float>(3)))};

  // Get the detected classes and scores
  const auto detectedClasses{getOutput<float>(1)};
  const auto detectedScores{getOutput<float>(2)};

  // Check if the detectedClasses and detectedScores are valid
  bool itUsable{detectedClasses != nullptr};
  itUsable &= detectedScores != nullptr;

  // Initialize the map to store the predictions
  std::map<int, float> predictions;

  // Iterate over the detected objects
  // In this model, countDetected cannot be more than 25.
  for (int i = 0; itUsable && (i < countDetected); i++) {
    const auto &classId = static_cast<uchar>(detectedClasses[i]);
    const auto &score = detectedScores[i];
    const bool itDetected{score >= constants::model::threshold};

    // If the object is detected with a high enough confidence score
    if (itDetected) {
      // Add the class to the predictions map if it doesn't exist
      predictions.try_emplace(classId, 0);
      // Update the max score for the class if necessary
      predictions[classId] = std::max(predictions[classId], score);
    }
  }

  return predictions;
}

QImage TFModel::transform(const QImage &image) const noexcept {
  QImage inputImage{image.scaled(constants::model::inputWidth,
                                 constants::model::inputHeight)};
  inputImage.convertTo(constants::model::imgFormat);
  return inputImage;
}
