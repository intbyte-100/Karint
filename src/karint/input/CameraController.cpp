#include <glm/trigonometric.hpp>
#include <iostream>
#include "CameraController.h"
#include "karint/math/kmath.h"

float karint::CameraController::getYaw() const {
    return yaw;
}

float karint::CameraController::getPitch() const {
    return pitch;
}

void karint::CameraController::setCamera(karint::Camera *camera) {
    CameraController::camera = camera;
    updateDirection();
    camera->direction = finalDirection;
}

void karint::CameraController::update() {
    camera->direction = math::linearInterpolation(camera->direction, finalDirection, -(smooth - 1));
}

std::function<void(double, double)> karint::CameraController::getMouseCallback() {
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

        updateDirection();
    };
}

void karint::CameraController::updateDirection() {
    finalDirection.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    finalDirection.y = sin(glm::radians(pitch));
    finalDirection.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    finalDirection = glm::normalize(finalDirection);
}
