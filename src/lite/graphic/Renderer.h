#pragma once

#include "lite/graphic/gl/ShaderProgram.h"
#include "Renderable.h"
#include "PerspectiveCamera.h"

namespace lite {
    class Renderer {
    private:
        ShaderProgram shaderProgram;
        Uniform projectionUniform;
        Uniform model;
        Uniform view;
    public:
        void setShader(ShaderProgram program);
        void use(PerspectiveCamera *camera);
        void draw(Renderable *renderable);
    };
}

