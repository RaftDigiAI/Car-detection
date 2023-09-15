#pragma once

using uchar = unsigned char;

namespace Constants {

struct Model {
  static constexpr int inputWidth = 320;
  static constexpr int inputHeight = 320;
  static constexpr int size = inputHeight * inputWidth * 3;
  static constexpr float threshold = 0.2;
  static constexpr uchar carClass = 2;
};

struct General {
  static constexpr int inferenceDelayMs = 1000;
  static constexpr char modelName[] = ":/res/model4";
};

}
