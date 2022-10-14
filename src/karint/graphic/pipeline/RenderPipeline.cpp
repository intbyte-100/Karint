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

    unit->init(shaderProgram);

    units.push_back(unit);
}

void karint::RenderPipeline::update() {
    for (auto unit: units)
        unit->update(false);
}
