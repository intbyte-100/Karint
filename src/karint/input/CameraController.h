#pragma once

#include <functional>
#include "karint/graphic/PerspectiveCamera.h"

namespace karint {
    class CameraController {
    private:
        PerspectiveCamera *camera;
        float yaw;
        float pitch;
        float lastX = 0, lastY = 0;
        bool firstMouse = true;
        glm::vec3 finalDirection;
    public:
        float smooth = 0;
        float sensitivity = 0.2f;
        std::function<void(double, double)> getMouseCallback();
        float getYaw() const;
        float getPitch() const;
        void setCamera(PerspectiveCamera *camera);
        void update();
    };
}