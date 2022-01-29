#include <glm/ext/matrix_transform.hpp>
#include "Camera.h"

void karint::Camera::update() {
    view = glm::lookAt(position, direction + position, glm::vec3(0.0f, 1.0f, 0.0f));
}
