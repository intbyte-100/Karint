#include "PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>

void karint::PerspectiveCamera::update(int width, int height) {
    projection = glm::perspective(glm::radians(viewAngle), (float) width / (float) height, near, far);
    Camera::update();
}


karint::PerspectiveCamera::PerspectiveCamera(float far, float near, float viewAngle) {
    this->far = far;
    this->near = near;
    this->viewAngle = viewAngle;
}






