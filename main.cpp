#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <lite/desktop/DesktopApplication.h>
#include <lite/desktop/lite.h>
#include "lite/graphic/gl/ElementBufferObject.h"
#include "lite/graphic/gl/ShaderProgram.h"
#include "lite/graphic/gl/Texture.h"
#include "lite/graphic/gl/VertexAttributeObject.h"
#include "lite/graphic/gl/VertexBufferObject.h"
#include <lite/graphic/attribute/AttributeArray.h>
#include "lite/graphic/gl/gl.h"
#include "lite/graphic/PerspectiveCamera.h"

class TestApp : public lite::Application {
    lite::ShaderProgram *program;
    lite::VertexBufferObject *vbo;
    lite::VertexAttributeObject *vao;
    lite::ElementBufferObject *ebo;
    lite::Texture texture;
    lite::Texture texture2;
    lite::Uniform projectionUniform;
    lite::Uniform modelUniform;
    lite::PerspectiveCamera camera;

    void onCreate() override {
        float vertices[] = {-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.5f, 0.5f, -0.5f, 1.0f,
                            1.0f,
                            0.5f, 0.5f, -0.5f, 1.0f, 1.0f, -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f,
                            0.0f,

                            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
                            0.5f, 0.5f, 0.5f, 1.0f, 1.0f, -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

                            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, -0.5f, -0.5f, -0.5f, 0.0f,
                            1.0f,
                            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, -0.5f, 0.5f, 0.5f, 1.0f,
                            0.0f,

                            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
                            0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

                            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.5f, -0.5f, 0.5f, 1.0f,
                            0.0f,
                            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, -0.5f, -0.5f, -0.5f, 0.0f,
                            1.0f,

                            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
                            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, -0.5f, 0.5f, -0.5f, 0.0f,
                            1.0f};

        program = lite::ShaderProgram::load("triangle.vert", "triangle.frag");
        vao = new lite::VertexAttributeObject();
        vbo = new lite::VertexBufferObject(vertices, sizeof(vertices));
        vao->use();
        vbo->draw(lite::STATIC_DRAW);

        lite::AttributeArray attributeArray;
        attributeArray.add(lite::POSITION_ATTRIBUTE);
        attributeArray.add(lite::TEXTURE_2D_ATTRIBUTE);
        attributeArray.enable();

        texture = lite::Texture::load("cl.jpg");
        texture2 = lite::Texture::load("awesomeface.png");
        projectionUniform = program->getUniform("projection");
        modelUniform = program->getUniform("model");

        program->use();
        program->getUniform("texture1").setInt(0);
        program->getUniform("texture2").setInt(1);

        camera = lite::PerspectiveCamera(100, 0.1f, 45);
        camera.position = glm::vec3(0.0f, 0.0f, 3.0f);
        camera.direction = glm::vec3(0.0f, 0.0f, -1.0f);
    }

    void render() override {
        lite::enable(lite::DEPTH_TEST);
        lite::clearScreen(0.5, 0.3, 0.6, 1.0, lite::COLOR_BUFFER | lite::DEPTH_BUFFER);

        int width, height;
        lite::Window::getCurrent()->getSize(&width, &height);

        texture.bind(0);
        texture2.bind(1);
        program->use();

        camera.update(width, height);

        glm::mat4 proj = camera.getProjection();
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        model = glm::rotate(model, (float) glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

        projectionUniform.setMatrix(proj, false);
        modelUniform.setMatrix(model, false);

        vao->use();
        lite::drawArrays(lite::TRIANGLE, 0, 36);
    }

public:
    ~TestApp() {
        delete vbo;
        delete vao;
        delete ebo;
        delete program;
        texture.dispose();
        texture2.dispose();
    }
};

int main() {

    lite::init();
    TestApp *app = new TestApp;
    lite::DesktopApplication(app, 800, 480, "lite engine").start();
    delete app;
    lite::terminate();
    return 0;
}
