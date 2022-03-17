#pragma once

#include "Uniform.h"
#include "UniformBlockBuffer.h"
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
        unsigned int getUniformBlockIndex(const char *name) const;
        void uniformBlockBinding(unsigned int index, unsigned int binding) const;
        void uniformBlockBinding(const char* name, unsigned int binding) const;
        void dispose();
        void use();
        static ShaderProgram *load(const std::string &vertex, const std::string &fragment);
    };
}
