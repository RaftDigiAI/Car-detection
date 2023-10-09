#pragma once

#include <QImage>

using uchar = unsigned char;

namespace Constants {

namespace Model {
constexpr int inputWidth = 320;
constexpr int inputHeight = 320;
constexpr int size = inputHeight * inputWidth * 3;
constexpr float threshold = 0.2;
constexpr uchar carClass = 2;
constexpr QImage::Format imgFormat = QImage::Format_RGB888;
};

namespace General {
constexpr int inferenceDelayMs = 1000;
constexpr char modelName[] = "model4";
};

}
