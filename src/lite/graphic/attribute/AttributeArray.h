#include "ColorAttribute.h"
#include "PositionAttribute.h"

#include <vector>

#pragma once

namespace lite {
    namespace {
        struct Attribute
        {
            short position;
            short type;
            char size;
        };
    }
    typedef short AttributeType;

    /** the first digit is a count of elements,
        the second digit is an element type, which compute by subtraction of type and GL_BYTE,
        the third digit is a type size
    **/
    constexpr AttributeType RGB_ATTRIBUTE = 0x364;
    constexpr AttributeType RGBA_ATTRIBUTE = 0x464;
    constexpr AttributeType POSITION_ATTRIBUTE = 0x364;
    constexpr AttributeType TEXTURE_2D_ATTRIBUTE = 0x264;

    class AttributeArray
    {
    private:
        short layerSize = 0;
        std::vector<Attribute> attributes;

    public:
        void enable();
        void add(AttributeType attribute);
    };
}
