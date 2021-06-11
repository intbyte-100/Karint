#include <glad/glad.h>
#include "VertexAttributeObject.h"

lite::VertexAttributeObject::VertexAttributeObject() {
    glGenVertexArrays(1, &vao);
}

void lite::VertexAttributeObject::dispose() {
    glDeleteVertexArrays(1, &vao);
}

void lite::VertexAttributeObject::use() {
    glBindVertexArray(vao);
}

lite::VertexAttributeObject::~VertexAttributeObject() {
    dispose();
}

