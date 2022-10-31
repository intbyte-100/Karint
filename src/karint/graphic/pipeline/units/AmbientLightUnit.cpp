#include "AmbientLightUnit.h"
#include "karint/graphic/pipeline/RenderPipeline.h"

void karint::AmbientLightUnit::update() {
    uniform.setFloat(color.x, color.y, color.z, 1);
}

void karint::AmbientLightUnit::init(RenderPipeline *pipeline) {
    uniform = pipeline->shaderProgram.getUniform("u_ambient");
}

uint64_t karint::AmbientLightUnit::unitBits() {
    return AMBIENT_LIGHT_UNIT;
}
