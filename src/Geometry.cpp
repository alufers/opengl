#include "Geometry.h"

Geometry::Geometry(std::vector<float> vertices) {
  this->vertices = vertices;
  glGenVertexArrays(1, &this->vao);
  glBindVertexArray(this->vao);
  glGenBuffers(1, &this->vbo);
  glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
  glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(float),
               &this->vertices[0], GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
}

void Geometry::draw() {
  glBindVertexArray(this->vao);
  glDrawArrays(GL_TRIANGLES, 0, this->vertices.size() / 3);
}

Geometry::~Geometry() {
  glDeleteBuffers(1, &this->vbo);

  glDeleteVertexArrays(1, &this->vao);
}
