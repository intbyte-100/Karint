#ifndef LITEENGINE_SHADERPROGRAM_H
#define LITEENGINE_SHADERPROGRAM_H

#include "Uniform.h"

#include <string>
namespace lite {
    class ShaderProgram {
    private:
        unsigned int shaderProgram;
    public:
        ~ShaderProgram();
        ShaderProgram(const char *vertex, const char *fragment);
        Uniform getUniform(const char *name);
        void dispose();
        void use();
        static ShaderProgram *load(const std::string &vertex, const std::string &fragment);
    };
}

#endif //LITEENGINE_SHADERPROGRAM_H
