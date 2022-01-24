#include "Renderer.h"
#include "lite/graphic/gl/gl.h"

void lite::Renderer::use(PerspectiveCamera *camera) {
    shaderProgram.use();
    auto projection = camera->getProjection();
    projectionUniform.setMatrix(projection, false);
    view.setMatrix(camera->view, false);
}

void lite::Renderer::setShader(lite::ShaderProgram program) {
    this->shaderProgram = program;
    projectionUniform = shaderProgram.getUniform("projection");
    model = shaderProgram.getUniform("model");
    view = shaderProgram.getUniform("view");
}

void lite::Renderer::draw(lite::Renderable *renderable) {
    model.setMatrix(renderable->model, false);
    renderable->use();
    gl::drawArrays(gl::TRIANGLE, 0, renderable->triangles);
}
