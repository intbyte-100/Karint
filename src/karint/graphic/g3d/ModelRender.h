#pragma once

#include "karint/graphic/pipeline/RenderPipeline.h"
#include "karint/graphic/pipeline/units/CameraUnit.h"
#include "karint/graphic/pipeline/units/AmbientLightUnit.h"
#include "karint/graphic/pipeline/units/MaterialUnit.h"
#include "karint/graphic/pipeline/units/LightUnit.h"

namespace karint {
    class ModelRender {
    private:
        RenderPipeline pipeline;
        CameraUnit cameraUnit;
        AmbientLightUnit ambientLightUnit;
        MaterialUnit materialUnit;
        LightUnit lightUnit;

    public:
        ModelRender(ShaderProgram program);

    };
}

