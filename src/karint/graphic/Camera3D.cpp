#include "Camera3D.h"
#include <glm/gtc/matrix_transform.hpp>

void karint::Camera3D::update(int width, int height) {
    projection = glm::perspective(glm::radians(viewAngle), (float) width / (float) height, near, far);
    Camera::update();
}


karint::Camera3D::Camera3D(float far, float near, float viewAngle) {
    this->far = far;
    this->near = near;
    this->viewAngle = viewAngle;
}






