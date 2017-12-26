#ifndef IMAGE_H
#define IMAGE_H
#include <stb_image.h>
#include <string>
#include <stdexcept>

class Image {
public:
  int width;
  int height;
  int nChannels;
  unsigned char *data;
  Image(const std::string &path);
  ~Image();
  Image(const Image &) = delete;
  Image &operator=(const Image &) = delete;
};
#endif
