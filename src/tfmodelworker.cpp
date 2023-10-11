#include "tfmodelworker.h"

TFModelWorker::TFModelWorker(QObject *parent)
    : QObject{parent}, mModel(nullptr) {}

void TFModelWorker::processImage(const QImage &image) noexcept {
  if (mModel == nullptr) {
    qCritical() << "TFModelWorker::processImage. "
                   "Model not created.";
    emit this->proccesFailed();
    return;
  }

  if (image.isNull()) {
    qCritical() << "TFModelWorker::processImage. Image not valid.";
    emit this->proccesFailed();
    return;
  }

  // Process results.
  const auto &[status, classId, score] = mModel->forward(image);
  // !status mean that `forward` not successful
  if (!status) {
    qCritical() << "TFModelWorker::processImage. Something wrong with `forward`";
    emit this->proccesFailed();
    return;
  }

  emit this->imageProcessed(classId, score);
}

void TFModelWorker::createModel() {
  const auto &usedModel = Constants::General::usedModel;
  switch (usedModel) {
  case DefinedModels::MetadataModel:
    mModel = std::make_unique<TFModelMetadata>();
    break;
  default:
    auto modelName = Constants::General::getModelName(usedModel);
    mModel = std::make_unique<TFModel>(modelName);
    break;
  }
}
