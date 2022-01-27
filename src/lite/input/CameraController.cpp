#include <glm/trigonometric.hpp>
#include "CameraController.h"
#include "lite/math/math.h"

float lite::CameraController::getYaw() const {
    return yaw;
}

float lite::CameraController::getPitch() const {
    return pitch;
}

void lite::CameraController::setCamera(lite::PerspectiveCamera *camera) {
    CameraController::camera = camera;
}

void lite::CameraController::update() {
    camera->direction = math::linearInterpolation(camera->direction, finalDirection, -(smooth - 1));
}

std::function<void(double, double)> lite::CameraController::getMouseCallback() {
    return [this](double x, double y){
        float xpos = static_cast<float>(x);
        float ypos = static_cast<float>(y);

        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos;
        lastX = xpos;
        lastY = ypos;

        float sensitivity = 0.2f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw += xoffset;
        pitch += yoffset;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        finalDirection.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        finalDirection.y = sin(glm::radians(pitch));
        finalDirection.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        finalDirection = glm::normalize(finalDirection);
    };
}
