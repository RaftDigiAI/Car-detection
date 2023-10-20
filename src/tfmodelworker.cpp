#include "tfmodelworker.h"

TFModelWorker::TFModelWorker(QObject *parent) : QObject{parent} {}

void TFModelWorker::processImage(const QImage &image) noexcept {

  if (mModel == nullptr) {
    qCritical() << "TFModelWorker::processImage. "
                   "Model not created.";
    emit this->imageProcessed({});
    return;
  }

  if (image.isNull()) {
    qCritical() << "TFModelWorker::processImage. Image not valid.";
    emit this->imageProcessed({});
    return;
  }

  // Process results.
  mTimer.restart();
  const auto &predictions = mModel->forward(image);
  emit this->executionTimeMeasured(mTimer.elapsed());
  emit this->imageProcessed(predictions);
}

void TFModelWorker::createModel() {
  const auto &usedModel = constants::general::usedModel;
  const auto modelName = constants::general::getModelName(usedModel);
  mModel = std::make_unique<TFModel>(modelName);
  if constexpr (constants::general::useGpu)
    mModel->enableGPU();
}
