#pragma once

#include <glm/glm.hpp>
#include "../gl/UniformBlockBuffer.h"

namespace karint {
    class Material {
    private:
        UniformBlockBuffer uniformBuffer;
    public:
        glm::vec3 color = glm::vec3(1);
        float diffuse = 1;
        float specularity = 0;

        void use(int binding);
        void update();
        void create();


        inline Material(glm::vec3 color, float diffuse = 1, float specularity = 0) {
            this->color = color;
            this->diffuse = diffuse;
            this->specularity = specularity;
        }
        Material() = default;
    };
}


