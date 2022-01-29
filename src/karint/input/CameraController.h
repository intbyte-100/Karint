#pragma once

#include <functional>
#include "karint/graphic/Camera.h"

namespace karint {
    class CameraController {
    private:
        Camera *camera;
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
        void setCamera(Camera *camera);
        void update();
    };
}