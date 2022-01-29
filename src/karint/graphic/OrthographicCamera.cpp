#include <glm/ext/matrix_clip_space.hpp>
#include "OrthographicCamera.h"

void karint::OrthographicCamera::ortho(float width, float height) {
    projection = glm::ortho(0.0f, width, 0.0f, height, 1.0f, 100.0f);
}
