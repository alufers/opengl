#ifndef TEXTURE_H
#define TEXTURE_H
#include "Image.h"
#include <GL/glew.h>
#include <glfw3.h>

class Texture {
public:
  GLuint texture;
  int width;
  int height;
  int nChannels;
  Texture(const Image &image);
  ~Texture();
  Texture(const Texture &) = delete;
  Texture &operator=(const Texture &) = delete;
  void bind();
};
#endif
