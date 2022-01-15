#include "glad/glad.h"
#include "VertexAttributeObject.h"

lite::VertexAttributeObject::VertexAttributeObject() {
    glGenVertexArrays(1, &id);
}

void lite::VertexAttributeObject::dispose() {
    glDeleteVertexArrays(1, &id);
}

void lite::VertexAttributeObject::use() {
    glBindVertexArray(id);
}

lite::VertexAttributeObject::~VertexAttributeObject() {
    dispose();
}

