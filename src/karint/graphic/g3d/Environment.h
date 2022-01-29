#pragma once

#include <glm/vec3.hpp>

namespace karint {
    class Renderer;
    class Environment {
        friend Renderer;
    private:
        glm::vec3 ambient {1.0};
    public:
        void resetAmbient();
        void addAmbient(glm::vec3 light);
    };
}
