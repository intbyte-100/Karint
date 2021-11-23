#include "VertexBufferObject.h"
#include <glad/glad.h>
#include <iostream>

lite::VertexBufferObject::VertexBufferObject(float *vertices, int size)
{
    this->vertices = vertices;
    this->size = size;
    glGenBuffers(1, &vbo);
}

void lite::VertexBufferObject::draw(unsigned int type)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, type);
}

void lite::VertexBufferObject::dispose()
{
    glDeleteBuffers(1, &vbo);
}

lite::VertexBufferObject::~VertexBufferObject() {
    dispose();
}
