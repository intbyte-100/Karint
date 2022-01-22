#include <iostream>
#include "glad/glad.h"
#include "VertexAttributeObject.h"



lite::attribute::Attribute* lite::attribute::RGB = new lite::attribute::Attribute(3, 6 ,4);
lite::attribute::Attribute* lite::attribute::RGBA = new lite::attribute::Attribute(4,6,4);
lite::attribute::Attribute* lite::attribute::POSITION = new lite::attribute::Attribute(3,6,4);
lite::attribute::Attribute* lite::attribute::TEXTURE_2D = new lite::attribute::Attribute(2,6,4);

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

void lite::VertexAttributeObject::enable(lite::attribute::Attribute attribute) {
    glVertexAttribPointer(0, attribute.count, attribute.type + GL_BYTE, false, attribute.count * attribute.size, nullptr);
}

void lite::VertexAttributeObject::enable(std::vector<attribute::Attribute> &attributes) {
    std::vector<short> attributePosition;
    short layerSize = 0;
    for (auto attribute: attributes){
        attributePosition.push_back(layerSize);
        layerSize+=attribute.count*attribute.size;
    }

    for(int i = 0; i < attributes.size(); i++){
        long position = attributePosition[i];
        glVertexAttribPointer(i, attributes[i].count, attributes[i].type+GL_BYTE, false, layerSize, (void*) position);
        glEnableVertexAttribArray(i);
    }
}



