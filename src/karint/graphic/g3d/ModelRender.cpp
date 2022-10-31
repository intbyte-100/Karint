#include "ModelRender.h"

karint::ModelRender::ModelRender(karint::ShaderProgram program) {
    pipeline.setShaderProgram(program);
    pipeline.add(&ambientLightUnit);
    pipeline.add(&cameraUnit);
    pipeline.add(&materialUnit);
    pipeline.add(&lightUnit);
}
