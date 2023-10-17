#include "tfmodelworker.h"

TFModelWorker::TFModelWorker(QObject *parent) : QObject{parent} {}

void TFModelWorker::processImage(const QImage &image) noexcept {
  if (mModel == nullptr) {
    qCritical() << "TFModelWorker::processImage. "
                   "Model not created.";
    emit this->proccessFailed();
    return;
  }

  if (image.isNull()) {
    qCritical() << "TFModelWorker::processImage. Image not valid.";
    emit this->proccessFailed();
    return;
  }

  // Process results.
  auto predictions = mModel->forward(image);
  // If predictions is empty, mean that `forward` not successful
  if (predictions.empty()) {
    qCritical()
        << "TFModelWorker::processImage. Something wrong with `forward`";
    emit this->proccessFailed();
    return;
  }

  emit this->imageProcessed(constants::model::carClass,
                            predictions[constants::model::carClass]);
}

void TFModelWorker::createModel() {
  const auto &usedModel = constants::general::usedModel;
  const auto modelName = constants::general::getModelName(usedModel);
  mModel = std::make_unique<TFModel>(modelName);
}
