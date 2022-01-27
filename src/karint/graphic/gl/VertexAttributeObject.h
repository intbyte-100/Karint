#ifndef karintENGINE_VERTEXATTRIBUTEOBJECT_H
#define karintENGINE_VERTEXATTRIBUTEOBJECT_H

#include <vector>

namespace karint{
    namespace attribute {
        typedef int Attribute;

        /** the first non zero digit is a count of elements,
            the second non zero digit is an element Attribute, which compute by subtraction of Attribute and GL_BYTE,
            the third non zero digit is a Attribute type size
        **/

        constexpr Attribute RGB = 0x030604;
        constexpr Attribute RGBA = 0x040604;
        constexpr Attribute POSITION = 0x030604;
        constexpr Attribute TEXTURE_2D = 0x020604;
    }

    class VertexAttributeObject {
    public:
        unsigned int id;
        ~VertexAttributeObject();
        void enable(attribute::Attribute attribute);
        void enable(std::vector<attribute::Attribute> &attributes);
        void use() const;
        void create();
        void dispose();
    };
}


#endif //karintENGINE_VERTEXATTRIBUTEOBJECT_H
