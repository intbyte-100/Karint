#pragma once


#include "karint/graphic/pipeline/RenderUnit.h"
#include "karint/graphic/Camera3D.h"

namespace karint {
    class CameraUnit : public RenderUnit {
    private:
        Uniform position;
        Uniform projection;
        Uniform view;

    public:
        uint64_t projectionType = 0;
        explicit CameraUnit(Camera *camera);
        CameraUnit() = default;
        Camera *camera;
        void update() override;
        void init(RenderPipeline *pipeline) override;
        uint64_t unitBits() override;
    };
}

