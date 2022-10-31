#pragma once

#include <string>
#include "karint/graphic/gl/ShaderProgram.h"


namespace karint {

    class RenderPipeline;

    /**
     * @param id is a render unit id
     *
     * converts a render unit id to render unit bits
    **/
    inline constexpr uint64_t renderUnitIdBits(int id){
        return ((uint64_t) id << 32) | 1 << (id);
    }

    /**
     * @param bits is a render unit bits
     *
     * converts a render unit bits id to render unit bit mask
    **/

    inline constexpr uint64_t renderUnitMask(uint64_t bits) {
        return bits | ((uint64_t) 0xFFFFFFFF);
    }

    /**
     * @param bits is a render unit bits
     *
     * converts a render unit bits id to render unit bit id
    **/
    inline constexpr int renderUnitIntId(uint64_t bits) {
        return (int) (bits >> 32);
    }

    constexpr uint64_t CAMERA_UNIT = renderUnitIdBits(0);
    constexpr uint64_t PERSPECTIVE_PROJECTION_UNIT = renderUnitIdBits(1);
    constexpr uint64_t COLOR_UNIT = renderUnitIdBits(2);
    constexpr uint64_t AMBIENT_LIGHT_UNIT = renderUnitIdBits(3);
    constexpr uint64_t DIFFUSE_LIGHT_UNIT = renderUnitIdBits(4);
    constexpr uint64_t DIRECTION_LIGHTS_UNIT = renderUnitIdBits(5);
    constexpr uint64_t POINT_LIGHTS_UNIT = renderUnitIdBits(6);
    constexpr uint64_t MATERIAL_UNIT = renderUnitIdBits(7);
    constexpr uint64_t SHADOW_MAP_UNIT = renderUnitIdBits(8);

    class RenderUnit {
    public:
        bool forceUpdate;
        virtual uint64_t unitBits() = 0;
        virtual void update() = 0;
        virtual void init(RenderPipeline *pipeline) = 0;
    };
}

