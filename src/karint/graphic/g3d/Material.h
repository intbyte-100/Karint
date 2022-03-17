#pragma once

#include <glm/glm.hpp>

namespace karint {
    class Material {
    public:
        glm::vec3 color;
        float diffuse = 1;
        float specularity = 0;
    };
}


