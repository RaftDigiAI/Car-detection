#pragma once

#include "abstracttfmodel.h"
#include "constants.hpp"
#include "definedmodels.hpp"
#include <memory>
#include <string>
#include <tensorflow/lite/delegates/gpu/delegate.h>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <tensorflow_lite_support/cc/task/vision/object_detector.h>

class TFModelMetadata : public AbstractTFModel {
public:
  explicit TFModelMetadata();

  /**
   * Make model forward
   * @param image Input image
   * @return Status, class id, score. Class id and score can be equal -1, if
   * objects not detected or was problems in process.
   */
  std::tuple<bool, int, float> forward(const QImage &image) noexcept override;

  /**
   * Enables GPU for the TFModel.
   * @return true if GPU is enabled successfully, false otherwise
   */
  bool enableGPU() override;

private:
  std::unique_ptr<tflite::task::vision::ObjectDetector> mObjectDetector;
};
