#include "ColorAttribute.h"
#include "PositionAttribute.h"

#include <vector>

#pragma once

namespace lite {
    namespace {
        struct Attribute
        {
            short position;
            int type;
            char size;
        };
    }
    typedef short AttributeType;

    /** the first digit is count of elements,
        the second digit is element type, wich compute by subtraction of type and GL_BYTE,
        the third digit is type size
    **/
    constexpr AttributeType RGB_ATTRIBUTE = 0x364;
    constexpr AttributeType RGBA_ATTRIBUTE = 0x464;
    constexpr AttributeType POSITION_ATTRIBUTE = 0x364;
    constexpr AttributeType TEXTURE_2D_ATTRIBUTE = 0x264;

    class AttributeArray
    {
    private:
        int layerSize = 0;
        std::vector<Attribute> attributes;

    public:
        void enable();
        void add(AttributeType attribute);
        ColorAttribute *getRGBAttribute(int layer);
        ColorAttribute *getRGBAAttribute(int layer);
        PositionAttribute *getPositionAttribute(int layer);
    };
}
