#include "AttributeArray.h"
#include "lite/graphic/gl/gl.h"
#include "glad/glad.h"
#include <iostream>

void lite::AttributeArray::enable()
{
    int attributeIndex = 0;
    for (Attribute i : attributes) {
        long position = i.position;
        lite::vertexAttribute(attributeIndex, i.size, i.type, false, layerSize, (void *) position);
        lite::enableVertexAttributeArray(attributeIndex++);
    }
}

void lite::AttributeArray::add(AttributeType attribute)
{
    Attribute attr;

    attr.type = (((char) attribute << 4) >> 8) + GL_BYTE;
    attr.size = (char) (attribute << 4) >> 4;
    attr.position = layerSize;

    layerSize += attr.size * (attribute >> 8);
    attributes.push_back(attr);
}
