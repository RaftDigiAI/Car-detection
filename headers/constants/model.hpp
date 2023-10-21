#pragma once

#include <QImage>

using uchar = unsigned char;

namespace constants {
namespace model {
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
} // namespace Constants
