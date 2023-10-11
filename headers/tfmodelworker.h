#pragma once

#include "abstracttfmodel.h"
#include "constants.hpp"
#include "definedmodels.hpp"
#include "tfmodel.h"
#include "tfmodelmetadata.h"
#include <QElapsedTimer>
#include <QImage>
#include <QObject>
#include <tuple>

class TFModelWorker : public QObject {
  Q_OBJECT
public:
  explicit TFModelWorker(QObject *parent = nullptr);

signals:
  void imageProcessed(const int &classRes, const double &scoreRes);
  void proccesFailed();

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
  std::unique_ptr<AbstractTFModel> mModel;
};
