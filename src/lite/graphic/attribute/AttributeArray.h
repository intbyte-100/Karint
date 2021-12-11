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
            char typeSize;
        };
    }
    typedef char AttributeType;
    constexpr AttributeType RGB_ATTRIBUTE = 3;
    constexpr AttributeType RGBA_ATTRIBUTE = 4;
    constexpr AttributeType POSITION_ATTRIBUTE = 3;
    constexpr AttributeType TEXTURE_2D_ATTRIBUTE = 2;

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
