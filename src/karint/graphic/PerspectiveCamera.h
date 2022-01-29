#pragma once

#include <glm/vec3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include "Camera.h"

namespace karint {
    class PerspectiveCamera: public Camera{
    private:
        float near;
        float far;
        float viewAngle;
    public:
        PerspectiveCamera() = default;
        PerspectiveCamera(float far, float near, float viewAngle);
        void update(int width, int height);
    };
}
