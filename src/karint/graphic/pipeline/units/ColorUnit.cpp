#include "ColorUnit.h"


void karint::ColorUnit::update(bool force) {
    if (force) {
        uniform.setVec3(color);
    }
}

void karint::ColorUnit::init(karint::ShaderProgram program) {
    uniform = program.getUniform("color");
}

uint64_t karint::ColorUnit::unitBits() {
    return COLOR_UNIT;
}
