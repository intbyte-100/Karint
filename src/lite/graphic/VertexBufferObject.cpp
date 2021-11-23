#include "VertexBufferObject.h"
#include <glad/glad.h>
#include <iostream>

lite::VertexBufferObject::VertexBufferObject(float *vertices, int size)
{
    this->vertices = vertices;
    this->size = size;
    glGenBuffers(1, &vbo);
}

void lite::VertexBufferObject::staticDraw()  {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
}

void lite::VertexBufferObject::dynamicDraw() {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_DYNAMIC_DRAW);
}

void lite::VertexBufferObject::streamDraw() {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STREAM_DRAW);
}

void lite::VertexBufferObject::dispose() {
    glDeleteBuffers(1, &vbo);
}

lite::VertexBufferObject::~VertexBufferObject() {
    dispose();
}
