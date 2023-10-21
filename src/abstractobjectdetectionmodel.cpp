#include "abstractobjectdetectionmodel.h"

QString
AbstractObjectDetectionModel::placeModel(const QString &modelName) const {
  if (QFile::exists(modelName))
    return modelName;

  QString modelPath{":/res/"};
  modelPath += modelName;

  QFile modelFile(modelPath);

  if (bool successfully = modelFile.copy(modelName); !successfully) {
    qCritical() << "TensorflowModel::placeModel. Model not exist.";
    return {};
  }

  return modelName;
}
