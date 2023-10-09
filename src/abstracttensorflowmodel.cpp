#include "abstracttensorflowmodel.h"

QString AbstractTensorflowModel::placeModel(const QString &modelName) {
  if (QFile::exists(modelName))
    return modelName;

  QString modelPath{":/res/"};
  modelPath += modelName;

  QFile modelFile(modelPath);
  bool successfully = modelFile.copy(modelName);

  if (!successfully) {
    qCritical() << "TensorflowModel::placeModel. Model not exist.";
    return {};
  }

  return modelName;
}
