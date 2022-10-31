#include "RenderPipeline.h"
#include "karint/util/logger.h"


void karint::RenderPipeline::add(karint::RenderUnit *unit) {
    uint64_t unitBits = unit->unitBits();
    uint64_t mask = renderUnitMask(unitBits);

    if (mask & unitsMask) {
        logger::error("karint::RenderPipeline", "two identical units have been added to the pipeline");
        return;
    }

    unitsMask = unitsMask | (uint32_t) mask;
    unitsLocationBits = unitsLocationBits | units.size() << 4 * renderUnitIntId(unitBits);

    unit->init(this);

    units.push_back(unit);
}

void karint::RenderPipeline::update() {
    shaderProgram.use();

    for (auto unit: units)
        if (unit->forceUpdate)
            unit->update();
}

void karint::RenderPipeline::setShaderProgram(karint::ShaderProgram program) {
    this->shaderProgram = program;
    uniformBlockId = 0;

    for (auto unit: units) {
        unit->init(this);
    }
}

int karint::RenderPipeline::registerUniformBlockId() {
    return uniformBlockId++;
}
