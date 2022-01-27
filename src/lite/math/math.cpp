#include <glm/trigonometric.hpp>
#include <iostream>
#include <glm/geometric.hpp>
#include "math.h"
#include "cmath"

float lite::math::middle(glm::vec3 vector) {
    return (vector.x + vector.y + vector.z) / 3.0f;
}

glm::vec3 lite::math::module(glm::vec3 vector) {
    return {module(vector.x), module(vector.y), module(vector.z)};
}

float lite::math::module(float module) {
    return module > 0 ? module : -module;
}

float lite::math::getAngle(glm::vec2 first, glm::vec2 second) {
    std::cout << (atan2(first.y - second.y, first.x - second.x) * 180) / PI + 90 << "\n";
    return (atan2(first.y - second.y, first.x - second.x) * 180) / PI + 90;;
}

float lite::math::normaliseDegrees(float degrees) {
    while (degrees > 360) degrees -= 360;
    while (degrees < 0) degrees += 360;
    return degrees;
}

glm::vec2 lite::math::rotate(glm::vec2 vector, float angle) {
    vector.x = (float) -sin(glm::radians(angle)) * vector.x;
    vector.y = (float) cos(glm::radians(angle)) * vector.y;
    return vector;
}
