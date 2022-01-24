#include <iostream>
#include "glad/glad.h"
#include "VertexAttributeObject.h"



void lite::VertexAttributeObject::create() {
    glGenVertexArrays(1, &id);
}

void lite::VertexAttributeObject::dispose() {
    glDeleteVertexArrays(1, &id);
}

void lite::VertexAttributeObject::use() const {
    glBindVertexArray(id);
}

lite::VertexAttributeObject::~VertexAttributeObject() {
    dispose();
}

void lite::VertexAttributeObject::enable(lite::attribute::Attribute attribute) {
    char count = (char) (attribute >> 8 * 2);
    char type = (char) (attribute >> 8);
    char size = (char) attribute;
    glVertexAttribPointer(0, count, type + GL_BYTE, false, count * size, nullptr);
}

void lite::VertexAttributeObject::enable(std::vector<attribute::Attribute> &attributes) {
    std::vector<short> attributePosition;
    short layerSize = 0;

    for (auto attribute: attributes) {
        char size = (char) attribute;
        attributePosition.push_back(layerSize);
        layerSize += ((char) (attribute >> 8 * 2)) * size;
    }

    for (int i = 0; i < attributes.size(); i++) {
        long position = attributePosition[i];
        char count = (char) (attributes[i] >> 8 * 2);
        char type = (char) (attributes[i] >> 8);
        glVertexAttribPointer(i, count, type + GL_BYTE, false, layerSize,(void *) position);
        glEnableVertexAttribArray(i);
    }
}



