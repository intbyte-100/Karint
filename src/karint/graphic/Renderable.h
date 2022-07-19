#pragma once

#include "glm/glm.hpp"
#include "karint/graphic/gl/VertexAttributeObject.h"
#include "karint/graphic/gl/VertexBufferObject.h"
#include "karint/graphic/g3d/Material.h"

namespace karint {
    class Renderable {
    public:
        VertexAttributeObject attributeObject;
        VertexBufferObject bufferObject;
        Material material;

        glm::mat4 model;
        int triangles = 0;

        inline void setVertices(float *vertices, int count, unsigned int type)  {
            bufferObject.setVertices(vertices, count, type);
        }

        inline void enableAttribute(attribute::Attribute attribute) {
            attributeObject.enable(attribute);
        }

        inline void enableAttributes(std::vector<attribute::Attribute> &attributes) {
            attributeObject.enable(attributes);
        }

        inline void use() {
            attributeObject.use();
            material.use(0);
        }

        inline void create() {
            attributeObject.create();
            attributeObject.use();
            bufferObject.create();
        }

        void dispose() {
            attributeObject.dispose();
            bufferObject.dispose();
        }
    };
}



