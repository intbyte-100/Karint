#include "Renderer.h"
#include "karint/graphic/gl/gl.h"


void karint::Renderer::use(Camera *camera) {
    shaderProgram.use();
    projectionUniform.setMatrix(camera->projection, false);
    view.setMatrix(camera->view, false);

    if (environment)
        ambient.setFloat(environment->ambient.x, environment->ambient.y, environment->ambient.z, 1);
}

void karint::Renderer::setShader(karint::ShaderProgram program) {
    this->shaderProgram = program;
    projectionUniform = shaderProgram.getUniform("projection");
    model = shaderProgram.getUniform("model");
    view = shaderProgram.getUniform("view");
    ambient = shaderProgram.getUniform("ambient");
    diffuseColor = shaderProgram.getUniform("diffuseColor");
    diffuseLightPosition = shaderProgram.getUniform("diffusePosition");
    shaderProgram.uniformBlockBinding("Material", 0);
}

void karint::Renderer::draw(karint::Renderable *renderable) {
    diffuseColor.setVec3(&environment->diffuseColor);
    diffuseLightPosition.setVec3(&environment->diffuseLightPosition);
    model.setMatrix(renderable->model, false);
    renderable->use();
    gl::drawArrays(gl::TRIANGLE, 0, renderable->triangles);
}

void karint::Renderer::setEnvironment(Environment* environment) {
    this->environment = environment;
}
