#include "CameraUnit.h"
#include "karint/graphic/pipeline/RenderPipeline.h"

karint::CameraUnit::CameraUnit(karint::Camera *camera) {
    this->camera = camera;
}

void karint::CameraUnit::update() {
    position.setVec3(camera->position);
    projection.setMatrix(camera->projection, false);
    view.setMatrix(camera->view, false);
}

void karint::CameraUnit::init(RenderPipeline *pipeline) {
    projection = pipeline->shaderProgram.getUniform("u_projection");
    position = pipeline->shaderProgram.getUniform("u_cameraPosition");
    view = pipeline->shaderProgram.getUniform("u_view");
}

uint64_t karint::CameraUnit::unitBits() {
    return CAMERA_UNIT | renderUnitMask(projectionType);
}
