#include "Display.h"

Display::Display() {
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize glfw");
  }
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                 GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  this->window =
      glfwCreateWindow(this->width, this->height, "Playground", NULL, NULL);
  if (this->window == NULL) {
    throw std::runtime_error("Failed to open GLFW window");
  }
  glfwMakeContextCurrent(this->window);
  glewExperimental = GL_TRUE;
  // Initialize GLEW
  if (glewInit() != GLEW_OK) {
    throw std::runtime_error("Failed to initialize GLEW");
  }
  glGetError();
  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Display::swapBuffers() { glfwSwapBuffers(this->window); }

void Display::poolEvents() { glfwPollEvents(); }

void Display::clear() { glClear(GL_COLOR_BUFFER_BIT); }

bool Display::shouldExit() {
  // Check if the ESC key was pressed or the window was closed
  return glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
         glfwWindowShouldClose(this->window) != 0;
}

Display::~Display() { glfwDestroyWindow(this->window); }
