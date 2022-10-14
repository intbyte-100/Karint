#include "CameraUnit.h"

karint::CameraUnit::CameraUnit(karint::Camera3D *camera3D) {
    this->camera = camera3D;
}

void karint::CameraUnit::update(bool force) {
    position.setVec3(camera->position);
    projection.setMatrix(camera->projection, false);
    view.setMatrix(camera->view, false);
}

void karint::CameraUnit::init(karint::ShaderProgram program) {
    projection = program.getUniform("projection");
    position = program.getUniform("position");
    view = program.getUniform("view");
}

uint64_t karint::CameraUnit::unitBits() {
    return CAMERA_UNIT | renderUnitMask(projectionType);
}
