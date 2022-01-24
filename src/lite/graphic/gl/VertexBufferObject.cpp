#include "VertexBufferObject.h"
#include "glad/glad.h"
#include <iostream>

void lite::VertexBufferObject::dispose()
{
    glDeleteBuffers(1, &id);
}

lite::VertexBufferObject::~VertexBufferObject() {
    dispose();
}

void lite::VertexBufferObject::setVertices(float *vertices, int count, unsigned int type) {
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), vertices, type);
}

void lite::VertexBufferObject::create() {
    glGenBuffers(1, &id);
}
