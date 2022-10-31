#include "ColorUnit.h"
#include "karint/graphic/pipeline/RenderPipeline.h"

void karint::ColorUnit::update() {
    uniform.setVec3(color);
}

void karint::ColorUnit::init(RenderPipeline *pipeline) {
    uniform = pipeline->shaderProgram.getUniform("u_color");
}

uint64_t karint::ColorUnit::unitBits() {
    return COLOR_UNIT;
}
