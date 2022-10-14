#pragma once

#include "Camera.h"

namespace karint {
    class Camera2D: public Camera{
    private:
        float width = 0;
        float height = 0;
        float far = 0;

    public:
        Camera2D() = default;
        void ortho(float width, float height);
    };
}
