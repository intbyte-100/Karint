#pragma once

#include "karint/graphic/pipeline/RenderUnit.h"


namespace karint {
    class LightUnit : public RenderUnit{
    private:
        Uniform positionUniform;
        Uniform directionUniform;
        Uniform colorUniform;
    public:
        glm::vec3 position;
        glm::vec3 direction;
        glm::vec3 color;
        void update() override;
        void init(RenderPipeline *pipeline) override;
        uint64_t unitBits() override;
    };
}


