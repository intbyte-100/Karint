#include "VertexBufferObject.h"
#include "glad/glad.h"
#include <iostream>

void karint::VertexBufferObject::dispose()
{
    glDeleteBuffers(1, &id);
}


void karint::VertexBufferObject::setVertices(float *vertices, int count, unsigned int type) const {
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), vertices, type);
}

void karint::VertexBufferObject::create() {
    glGenBuffers(1, &id);
}
