#include "AmbientUnit.h"



void karint::AmbientLightUnit::update(bool force) {
    if (force) {
        uniform.setFloat(color.x, color.y, color.z, 1);
    }
}

void karint::AmbientLightUnit::init(karint::ShaderProgram program) {
    uniform = program.getUniform("ambient");
}

uint64_t karint::AmbientLightUnit::unitBits() {
    return AMBIENT_LIGHT_UNIT;
}
