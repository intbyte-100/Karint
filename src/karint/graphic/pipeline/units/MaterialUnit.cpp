#include "MaterialUnit.h"
#include "karint/graphic/pipeline/RenderPipeline.h"

void karint::MaterialUnit::update() {

}

void karint::MaterialUnit::init(RenderPipeline *pipeline) {
    binding = pipeline->registerUniformBlockId();
    pipeline->shaderProgram.uniformBlockBinding("Material", binding);
}

uint64_t karint::MaterialUnit::unitBits() {
    return MATERIAL_UNIT;
}
