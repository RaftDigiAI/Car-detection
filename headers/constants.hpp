#pragma once

#include "definedmodels.hpp"
#include <QImage>
#include <map>

using uchar = unsigned char;

namespace Constants {
namespace Model {
// Define the input width and height of the model
constexpr int inputWidth = 320;
constexpr int inputHeight = 320;

// Calculate the size of the input tensor
constexpr int size = inputHeight * inputWidth * 3;

// Set the threshold for object detection
constexpr float threshold = 0.2;

// Define the class index for cars
constexpr uchar carClass = 2;

// Set the image format for the input
constexpr QImage::Format imgFormat = QImage::Format_RGB888;
}; // namespace Model

namespace General {
// Set the delay for inference in milliseconds
constexpr int inferenceDelayMs = 1000;

// Set the used model for inference
constexpr DefinedModels usedModel = DefinedModels::DefaultModel;

// Get the name of the model based on the enum value
constexpr const char *getModelName(const DefinedModels &model) {
  switch (model) {
  case DefinedModels::DefaultModel:
    return "default model2";
  case DefinedModels::MetadataModel:
    return "model with metadata";
  case DefinedModels::QuantModel:
    return "model int8";
  }
}
}; // namespace General

} // namespace Constants