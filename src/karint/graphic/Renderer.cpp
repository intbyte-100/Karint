#include "Renderer.h"
#include "karint/graphic/gl/gl.h"

void karint::Renderer::use(Camera *camera) {
    shaderProgram.use();
    projectionUniform.setMatrix(camera->projection, false);
    view.setMatrix(camera->view, false);
}

void karint::Renderer::setShader(karint::ShaderProgram program) {
    this->shaderProgram = program;
    projectionUniform = shaderProgram.getUniform("projection");
    model = shaderProgram.getUniform("model");
    view = shaderProgram.getUniform("view");
}

void karint::Renderer::draw(karint::Renderable *renderable) {
    model.setMatrix(renderable->model, false);
    renderable->use();
    gl::drawArrays(gl::TRIANGLE, 0, renderable->triangles);
}
