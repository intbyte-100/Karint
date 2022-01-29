#pragma once

#include "karint/graphic/gl/ShaderProgram.h"
#include "Renderable.h"
#include "Camera.h"
#include "karint/graphic/g3d/Environment.h"

namespace karint {
    class Renderer {
    private:
        Environment *environment = nullptr;
        ShaderProgram shaderProgram;
        Uniform projectionUniform;
        Uniform model;
        Uniform view;
        Uniform ambient;
    public:
        void setEnvironment(Environment* environment);
        void setShader(ShaderProgram program);
        void use(Camera *camera);
        void draw(Renderable *renderable);
        void begin();
    };
}

