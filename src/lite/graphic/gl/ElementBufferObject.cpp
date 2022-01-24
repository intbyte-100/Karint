#include "ElementBufferObject.h"
#include "glad/glad.h"


void lite::ElementBufferObject::setIndices(unsigned int *indices, int count,  unsigned int type)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * count, indices, type);
}

void lite::ElementBufferObject::create() {
    glGenBuffers(1, &id);
}
