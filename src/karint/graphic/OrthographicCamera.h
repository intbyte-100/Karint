#pragma once

#include "Camera.h"

namespace karint {
    class OrthographicCamera: public Camera{
    private:
        float width = 0;
        float height = 0;
        float far = 0;

    public:
        OrthographicCamera() = default;
        void ortho(float width, float height);
    };
}
