#pragma once

#include <glm/vec3.hpp>

namespace karint {
    class Renderer;
    class Environment {
        friend Renderer;
    private:
        glm::vec3 ambient {1.0};
        glm::vec3 diffuseColor {0};
    public:
        glm::vec3 diffuseLightPosition;
        void resetAmbient();
        void addAmbient(glm::vec3 light);
        void setDiffuseLight(glm::vec3 position, glm::vec3 color);
    };
}
