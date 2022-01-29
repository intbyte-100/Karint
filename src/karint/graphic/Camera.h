#pragma once

#include <glm/glm.hpp>

namespace karint {
    class Camera {
    public:
        glm::mat4 projection;
        glm::mat4 view;
        glm::vec3 direction = glm::vec3(0);
        glm::vec3 position = glm::vec3(0);
        void update();
    };
}

