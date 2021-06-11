#ifndef LITEENGINE_SHADERPROGRAM_H
#define LITEENGINE_SHADERPROGRAM_H


#include <string>
namespace lite {
    class ShaderProgram {
    private:
        unsigned int shaderProgram;
    public:
        ~ShaderProgram();
        ShaderProgram(const char *vertex, const char *fragment);
        void dispose();
        void use();
    };
}

#endif //LITEENGINE_SHADERPROGRAM_H
