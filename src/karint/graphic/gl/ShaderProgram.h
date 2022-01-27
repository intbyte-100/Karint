#pragma once

#include "Uniform.h"
#include <string>

namespace karint {
    class ShaderProgram {
    private:
        unsigned int shaderProgram = 0;
    public:
        ~ShaderProgram();
        ShaderProgram()= default;
        ShaderProgram(const char *vertex, const char *fragment);
        Uniform getUniform(const char *name);
        void dispose();
        void use();
        static ShaderProgram *load(const std::string &vertex, const std::string &fragment);
    };
}
