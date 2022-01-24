#pragma once
#include "glm/glm.hpp"
#include "lite/graphic/gl/VertexAttributeObject.h"
#include "lite/graphic/gl/VertexBufferObject.h"

namespace lite {
    class Renderable {
    public:
        VertexAttributeObject attributeObject;
        VertexBufferObject bufferObject;
        glm::mat4 model;
        int triangles = 0;

        inline void setVertices(float *vertices, int count, unsigned int type){
            bufferObject.setVertices(vertices, count, type);
        }

        inline void enableAttribute(attribute::Attribute attribute){
            attributeObject.enable(attribute);
        }

        inline void enableAttributes(std::vector<attribute::Attribute> &attributes){
            attributeObject.enable(attributes);
        }

        inline void use() const{
            attributeObject.use();
        }

        inline void create(){
            attributeObject.create();
            attributeObject.use();
            bufferObject.create();
        }
    };
}



