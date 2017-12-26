#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <GL/glew.h>
#include <glfw3.h>
#include <vector>
#include <iostream>

class Geometry {
public:
  std::vector<float> vertices;
  GLuint vbo;
  GLuint vao;
  Geometry(std::vector<float> vertices);
  ~Geometry();
  Geometry(const Geometry &) = delete;
  Geometry &operator=(const Geometry &) = delete;
  void draw();
};
#endif
