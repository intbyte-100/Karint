#include <glm/trigonometric.hpp>
#include <iostream>
#include <glm/geometric.hpp>
#include "kmath.h"
#include "cmath"

float karint::math::middle(glm::vec3 vector) {
    return (vector.x + vector.y + vector.z) / 3.0f;
}

glm::vec3 karint::math::module(glm::vec3 vector) {
    return {module(vector.x), module(vector.y), module(vector.z)};
}

float karint::math::module(float module) {
    return module > 0 ? module : -module;
}

float karint::math::getAngle(glm::vec2 first, glm::vec2 second) {
    std::cout << (atan2(first.y - second.y, first.x - second.x) * 180) / PI + 90 << "\n";
    return (atan2(first.y - second.y, first.x - second.x) * 180) / PI + 90;;
}

float karint::math::normaliseDegrees(float degrees) {
    while (degrees > 360) degrees -= 360;
    while (degrees < 0) degrees += 360;
    return degrees;
}

glm::vec2 karint::math::rotate(glm::vec2 vector, float angle) {
    vector.x = (float) -sin(glm::radians(angle)) * vector.x;
    vector.y = (float) cos(glm::radians(angle)) * vector.y;
    return vector;
}
