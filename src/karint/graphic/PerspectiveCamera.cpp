#include "PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>

void karint::PerspectiveCamera::update(int width, int height) {
    projection = glm::perspective(glm::radians(viewAngle), (float) width / (float) height, near, far);
    update();
}

void karint::PerspectiveCamera::update() {
    view = glm::lookAt(position, direction + position, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 karint::PerspectiveCamera::getProjection() {
    return projection;
}

karint::PerspectiveCamera::PerspectiveCamera(float far, float near, float viewAngle) {
    this->far = far;
    this->near = near;
    this->viewAngle = viewAngle;
}





