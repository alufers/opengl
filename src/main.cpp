// Link statically with GLEW
#define GLEW_STATIC

// Headers
#include "AssetManager.h"
#include "Display.h"
#include "Geometry.h"
#include "Image.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include <GL/glew.h>
#include <iostream>
#include <memory>
#include <vector>

int main() {
  AssetManager am;

  auto display = std::make_unique<Display>();
  std::vector<float> vertices = {
      // positions          // colors           // texture coords
      0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
      0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
  };

  auto sp =
      std::make_unique<ShaderProgram>(am, "../src/shaders/basic/manifest.json");
  auto tex = std::make_unique<Texture>(Image("../texture.png"));
  auto geo = std::make_unique<Geometry>(vertices);

  bool running = true;
  while (running) {
    display->poolEvents();
    if (display->shouldExit()) {
      running = false;
    }
    display->clear();
    tex->bind();
    sp->use();
    sp->setFloat("time", glfwGetTime());
    geo->draw();
    // Swap buffers
    display->swapBuffers();
  }

  return 0;
}
