#include "PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>

void lite::PerspectiveCamera::update(int width, int height) {
    projection = glm::perspective(glm::radians(viewAngle), (float) width / (float) height, near, far);
    update();
}

void lite::PerspectiveCamera::update() {
    view = glm::lookAt(position, direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 lite::PerspectiveCamera::getProjection() {
    return projection;
}

lite::PerspectiveCamera::PerspectiveCamera(float far, float near, float viewAngle) {
    this->far = far;
    this->near = near;
    this->viewAngle = viewAngle;
}





