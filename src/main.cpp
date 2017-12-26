// Link statically with GLEW
#define GLEW_STATIC

// Headers
#include "AssetManager.h"
#include "Display.h"
#include "Geometry.h"
#include "ShaderProgram.h"
#include <GL/glew.h>
#include <iostream>
#include <memory>
#include <vector>

int main() {
  AssetManager am;
  auto display = std::make_unique<Display>();

  std::vector<float> vertices = {
      0.5f, 0.5f, 0.0f,   // top right
      0.5f, -0.5f, 0.0f,  // bottom right
      -0.5f, 0.5f, 0.0f,  // top left
                          // second triangle
      0.5f, -0.5f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f, 0.0f   // top left
  };

  auto geo = std::make_unique<Geometry>(vertices);

  auto sp = std::make_unique<ShaderProgram>(am, "../src/shaders/basic/manifest.json");

  bool running = true;
  while (running) {
    display->poolEvents();
    if (display->shouldExit()) {
      running = false;
    }
    display->clear();
    sp->use();
    sp->setFloat("time", glfwGetTime());
    geo->draw();
    // Swap buffers
    display->swapBuffers();
  }

  return 0;
}
