#include "Image.h"

Image::Image(const std::string &path) {
  this->data =
      stbi_load(path.c_str(), &this->width, &this->height, &this->nChannels, 0);
      if(!this->data) {
          throw std::runtime_error("Could not load image.");
      }
}

Image::~Image() { stbi_image_free(this->data); }
