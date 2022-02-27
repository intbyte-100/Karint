#include <glm/trigonometric.hpp>
#include <iostream>
#include <glm/geometric.hpp>
#include "math.h"
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

std::vector<glm::vec3> karint::math::calculateNormals(float *triangles, int count, int step) {
    std::vector<glm::vec3> normals(count/(3+step)*3);
    int index = 0;
    for (int i = 0; i < count; i+=(3+step)*3) {
        glm::vec3 vert(triangles[i], triangles[i+1], triangles[i+2]);
        glm::vec3 vert2(triangles[i+step+3], triangles[i+step+4], triangles[i+step+5]);
        glm::vec3 vert3(triangles[i+step*2+6],triangles[i+step*2+7], triangles[i+step*2+8]);

        glm::vec3 vector = vert3 - vert;
        glm::vec3 vector2 = vert2 - vert;

        auto normal = glm::cross(vector, vector2);
        normals[index++] = normal;
        normals[index++] = normal;
        normals[index++] = normal;
    }
    return normals;
}
