#include <iostream>
#include "glad/glad.h"
#include "VertexAttributeObject.h"



void karint::VertexAttributeObject::create() {
    glGenVertexArrays(1, &id);
}

void karint::VertexAttributeObject::dispose() {
    glDeleteVertexArrays(1, &id);
}

void karint::VertexAttributeObject::use() const {
    glBindVertexArray(id);
}

karint::VertexAttributeObject::~VertexAttributeObject() {
    dispose();
}

void karint::VertexAttributeObject::enable(karint::attribute::Attribute attribute) {
    char count = (char) (attribute >> 8 * 2);
    char type = (char) (attribute >> 8);
    char size = (char) attribute;
    glVertexAttribPointer(0, count, type + GL_BYTE, false, count * size, nullptr);
}

void karint::VertexAttributeObject::enable(std::vector<attribute::Attribute> &attributes) {
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



