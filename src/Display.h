#ifndef DISPLAY_H
#define DISPLAY_H
#include <GL/glew.h>
#include <glfw3.h>
#include <iostream>
#include <stdexcept>

class Display {
public:
  int width = 1600;
  int height = 900;
  GLFWwindow *window;
  Display();
  ~Display();
  Display(const Display &) = delete;
  Display &operator=(const Display &) = delete;

  void swapBuffers();
  void clear();
  void poolEvents();
  bool shouldExit();
};
#endif
