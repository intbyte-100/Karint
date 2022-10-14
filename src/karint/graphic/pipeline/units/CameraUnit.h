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
        explicit CameraUnit(Camera3D *camera3D);
        CameraUnit() = default;
        Camera3D *camera;
        void update(bool force) override;
        void init(ShaderProgram program) override;
        uint64_t unitBits() override;
    };
}

