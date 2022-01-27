#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace lite {
    namespace math {
        constexpr double PI = 3.1415926;
        template<typename T>
        T linearInterpolation(T from, T to, float progress) {
            return from - (from - to) * progress;
        }

        float middle(glm::vec3 vector);
        float module(float module);
        glm::vec3 module(glm::vec3 vector);
        float getAngle(glm::vec2 first, glm::vec2 second);
        float normaliseDegrees(float degrees);
        glm::vec2 rotate(glm::vec2 vector, float angle);
    }
}


