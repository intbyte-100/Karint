#include "AttributeArray.h"
#include "../gl.h"

void lite::AttributeArray::enable()
{
    int attributeIndex = 0;
    for (Attribute &i : attributes) {
        long position = i.position;
        lite::vertexAttribute(attributeIndex, i.size, i.type, false, layerSize, (void *) position);
        lite::enableVertexAttributeArray(attributeIndex++);
    }
}

void lite::AttributeArray::add(AttributeType attribute)
{
    Attribute attr;

    switch (attribute) {
        case RGBA_ATTRIBUTE:
        case POSITION_ATTRIBUTE:
        case TEXTURE_2D_ATTRIBUTE:
            attr.type = lite::FLOAT;
            attr.typeSize = sizeof(float);
            break;
        default:
            return;
    }

    attr.size = attribute;
    attr.position = layerSize;
    attributes.push_back(attr);

    layerSize += attribute * attr.typeSize;
}
