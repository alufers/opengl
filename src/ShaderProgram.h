#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H
#include <string>
#include <GL/glew.h>
#include <glfw3.h>
#include <stdexcept>
#include <vector>
#include <mpark/variant.hpp>
#include <json.hpp>
#include "AssetManager.h"
using json = nlohmann::json;

const int SHADER_ERROR_LOG_MAX_LENGTH = 1024;

typedef mpark::variant<int, float, bool> uniformValue;

class AssetManager;

class ShaderProgram {
public:
  std::string vertexSource;
  std::string fragmentSource;
  GLuint shaderProgram;
  ShaderProgram(std::string vertexSource, std::string fragmentSource);
  ShaderProgram(AssetManager &asssetManager, const std::string &manifestPath);
  ~ShaderProgram();
  ShaderProgram(const ShaderProgram &) = delete;
  ShaderProgram &operator=(const ShaderProgram &) = delete;
  void use() const;
  void setUniform(const std::string &name, const uniformValue value) const;
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
private:
    GLuint compileVertex();
    GLuint compileFragment();
    void doCompileAndLink(std::string vertexSource, std::string fragmentSource);
};
#endif
