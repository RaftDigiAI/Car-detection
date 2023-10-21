#pragma once

#include "definedmodels.hpp"

namespace constants {
namespace general {
// Set the delay for inference in milliseconds
constexpr int inferenceDelayMs = 1000;

// Set the used model for inference
constexpr DefinedModels usedModel = DefinedModels::QuantModel;

// Set flag if need use gpu delegate.
constexpr bool useGpu = false;

// Get the name of the model based on the enum value
constexpr const char *getModelName(const DefinedModels &model) {
  switch (model) {
  case DefinedModels::DefaultModel:
    return "default model";
  case DefinedModels::QuantModel:
    return "model int8";
  }
}

}; // namespace General
} // namespace Constants
