#ifndef LITEENGINE_VERTEXATTRIBUTEOBJECT_H
#define LITEENGINE_VERTEXATTRIBUTEOBJECT_H

#include <vector>

namespace lite{
    namespace attribute {
        class Attribute {
        public:
            short count, type, size;
            Attribute(short count, short type, short size){
                this->count = count;
                this->type = type;
                this->size = size;
            }
        };

        /** the first argument is a count of elements,
            the second argument is an element Attribute, which compute by subtraction of Attribute and GL_BYTE,
            the third argument is a Attribute size
        **/
        extern Attribute* RGB;
        extern Attribute* RGBA;
        extern Attribute* POSITION;
        extern Attribute* TEXTURE_2D;
    }

    class VertexAttributeObject {
    public:
        unsigned int id;
        ~VertexAttributeObject();
        VertexAttributeObject();
        void enable(attribute::Attribute attribute);
        void enable(std::vector<attribute::Attribute> &attributes);
        void use();
        void dispose();
    };
}


#endif //LITEENGINE_VERTEXATTRIBUTEOBJECT_H
