#include "Vertex.h"
#include "glad/glad.h"

void karint::Vertex::calculateNormals(std::vector<Vertex> *vertices) {
    for (int i = 0; i < vertices->size(); i+=3) {
        auto vector = vertices->at(i+2).position - vertices->at(i).position;
        auto vector2 = vertices->at(i+1).position - vertices->at(i).position;
        auto normal = glm::cross(vector, vector2);
        vertices->at(i).normal = normal;
        vertices->at(i+1).normal = normal;
        vertices->at(i+2).normal = normal;
    }
}

void karint::Vertex::enableDefaultVertexAttributes() {
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 32, (void*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 32, (void*) 12);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, false, 32, (void*) 24);
    glEnableVertexAttribArray(2);
}
