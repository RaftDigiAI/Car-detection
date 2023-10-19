#pragma once

#include "abstractobjectdetectionmodel.h"
#include "constants/general.hpp"
#include "definedmodels.hpp"
#include "tfmodel.h"
#include <QElapsedTimer>
#include <QImage>
#include <QObject>
#include <tuple>

class TFModelWorker : public QObject {
  Q_OBJECT
public:
  explicit TFModelWorker(QObject *parent = nullptr);

signals:
  void imageProcessed(const std::map<int, double> &predictions);

public slots:
  /**
   * Apply transform to image and push result image to model.
   * @param image Image for model.
   */
  void processImage(const QImage &image) noexcept;

  /**
   * Creates a TFModel based on the value of usedModel.
   */
  void createModel();

private:
  std::unique_ptr<AbstractObjectDetectionModel> mModel;
};
