#ifndef MESH_H
#define MESH_H
#include <GL/glew.h>
#include <glfw3.h>
#include <vector>
#include <iostream>

class Mesh {
public:
  std::vector<float> vertices;
  GLuint vertexBuffer;
  Mesh();
  Mesh(std::vector<float> vertices);
  ~Mesh();
  Mesh(const Mesh &) = delete;
  Mesh &operator=(const Mesh &) = delete;
  void uploadToGPU();
  void draw();
};
#endif
