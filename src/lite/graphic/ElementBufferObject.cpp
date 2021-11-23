#include "ElementBufferObject.h"
#include "glad/glad.h"

lite::ElementBufferObject::ElementBufferObject(unsigned int size, unsigned int *indices)
{
    glGenBuffers(1, &id);
    setIndices(size, indices);
}

void lite::ElementBufferObject::setIndices(unsigned int size, unsigned int *indices)
{
    this->indicesCount = size;
    this->indices = indices;
}

void lite::ElementBufferObject::draw(unsigned int type)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicesCount, indices, type);
}
