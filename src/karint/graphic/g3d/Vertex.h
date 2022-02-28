#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace karint {
    class Vertex {
    public:
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 textureCoords;
        static void calculateNormals(std::vector<Vertex> *vertices);
        static void enableDefaultVertexAttributes();
    };
}