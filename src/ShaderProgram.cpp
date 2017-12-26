#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string vertexSource,
                             std::string fragmentSource) {
  this->doCompileAndLink(vertexSource, fragmentSource);
}

ShaderProgram::ShaderProgram(AssetManager &assetManager, const std::string &manifestPath) {
  json manifestData = assetManager.loadJson(manifestPath);
  std::string manifestDir = assetManager.dirname(manifestPath);
  std::string vertexShaderPath = assetManager.resolvePath(manifestData["vertexShader"]["path"].get<std::string>(), manifestDir);
  
  std::string fragmentShaderPath =  assetManager.resolvePath(manifestData["fragmentShader"]["path"].get<std::string>(), manifestDir);
 
  this->doCompileAndLink(assetManager.loadText(vertexShaderPath), assetManager.loadText(fragmentShaderPath));
  
}

ShaderProgram::~ShaderProgram() { glDeleteProgram(this->shaderProgram); }

void ShaderProgram::use() const { glUseProgram(this->shaderProgram); }

void ShaderProgram::setUniform(const std::string &name,
                               const uniformValue value) const {
  if (mpark::holds_alternative<int>(value)) {
    this->setInt(name, mpark::get<int>(value));
  } else if (mpark::holds_alternative<float>(value)) {
    this->setFloat(name, mpark::get<float>(value));
  } else if (mpark::holds_alternative<bool>(value)) {
    this->setBool(name, mpark::get<bool>(value));
  }
}

void ShaderProgram::setBool(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()),
              (int)value);
}
void ShaderProgram::setInt(const std::string &name, int value) const {
  glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}
void ShaderProgram::setFloat(const std::string &name, float value) const {
  glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}

GLuint ShaderProgram::compileVertex() {
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const char *vertexSourceC = this->vertexSource.c_str();
  glShaderSource(vertexShader, 1, &vertexSourceC, NULL);
  glCompileShader(vertexShader);

  // check for errors
  int success;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    std::vector<char> infoLog(SHADER_ERROR_LOG_MAX_LENGTH);
    glGetShaderInfoLog(vertexShader, SHADER_ERROR_LOG_MAX_LENGTH, NULL,
                       infoLog.data());
    std::string infoLogStr(&infoLog[0]);
    throw std::runtime_error("Vertex shader compilation failed" + infoLogStr);
  }
  return vertexShader;
}

GLuint ShaderProgram::compileFragment() {
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char *fragmentSourceC = this->fragmentSource.c_str();
  glShaderSource(fragmentShader, 1, &fragmentSourceC, NULL);
  glCompileShader(fragmentShader);

  // check for errors
  int success;
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    std::vector<char> infoLog(SHADER_ERROR_LOG_MAX_LENGTH);
    glGetShaderInfoLog(fragmentShader, SHADER_ERROR_LOG_MAX_LENGTH, NULL,
                       infoLog.data());
    std::string infoLogStr(&infoLog[0]);
    throw std::runtime_error("Fragment shader compilation failed" + infoLogStr);
  }
  return fragmentShader;
}

void ShaderProgram::doCompileAndLink(std::string vertexSource,
                                     std::string fragmentSource) {
  this->vertexSource = vertexSource;
  this->fragmentSource = fragmentSource;
  // Create and compile the vertex shader
  GLuint vertexShader = this->compileVertex();
  // Create and compile the fragment shader
  GLuint fragmentShader = this->compileFragment();

  this->shaderProgram = glCreateProgram();
  glAttachShader(this->shaderProgram, vertexShader);
  glAttachShader(this->shaderProgram, fragmentShader);
  glBindFragDataLocation(this->shaderProgram, 0, "outColor");
  glLinkProgram(this->shaderProgram);

  // remove the shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}
