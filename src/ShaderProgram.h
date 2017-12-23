#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H
#include <string>
class ShaderProgram {
    public:
        std::string vertexSource;
        std::string fragmentSource;
        ShaderProgram();
        ~ShaderProgram();
        void use();
};
#endif
