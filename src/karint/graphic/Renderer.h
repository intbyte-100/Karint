#pragma once

#include "karint/graphic/gl/ShaderProgram.h"
#include "Renderable.h"
#include "Camera.h"

namespace karint {
    class Renderer {
    private:
        ShaderProgram shaderProgram;
        Uniform projectionUniform;
        Uniform model;
        Uniform view;
    public:
        void setShader(ShaderProgram program);
        void use(Camera *camera);
        void draw(Renderable *renderable);
    };
}

