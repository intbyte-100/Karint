#pragma once

#include "karint/graphic/pipeline/RenderUnit.h"


namespace karint {
    class DiffuseLightUnit : public RenderUnit{
    private:
    public:
        void update(bool force) override;
        void init(ShaderProgram program) override;
        uint64_t unitBits() override;
    };
}


