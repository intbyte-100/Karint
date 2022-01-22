#include <glm/gtc/matrix_transform.hpp>
#include <lite/desktop/DesktopApplication.h>
#include <lite/desktop/lite.h>
#include "lite/graphic/gl/ElementBufferObject.h"
#include "lite/graphic/gl/ShaderProgram.h"
#include "lite/graphic/gl/Texture.h"
#include "lite/graphic/gl/VertexAttributeObject.h"
#include "lite/graphic/gl/VertexBufferObject.h"
#include <iostream>
#include "lite/graphic/gl/gl.h"
#include "lite/graphic/PerspectiveCamera.h"


using namespace lite;

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
        std::cout << lite::gl::getBackendInfo() << "\n";

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

        program = ShaderProgram::load("triangle.vert", "triangle.frag");
        vao = new VertexAttributeObject();
        vbo = new VertexBufferObject(vertices, sizeof(vertices));
        vao->use();
        vbo->draw(lite::gl::STATIC_DRAW);

        std::vector<attribute::Attribute> array{
            attribute::POSITION,
            attribute::TEXTURE_2D
        };

        vao->enable(array);

        texture = Texture::load("stone.jpeg");
        texture2 = Texture::load("stone.jpeg");
        projectionUniform = program->getUniform("projection");
        modelUniform = program->getUniform("model");

        program->use();
        program->getUniform("texture1").setInt(0);
        program->getUniform("texture2").setInt(1);

        camera = PerspectiveCamera(100, 0.1f, 45);
        camera.position = glm::vec3(1.0f, 4.0f, 6.0f);
        camera.direction = glm::vec3(1.0f, 0.0f, -1.0f);
    }

    void render() override {
        gl::enable(lite::gl::DEPTH_TEST);
        gl::clearScreen(135 / 255.0f, 206 / 255.0f, 235 / 255.0f, 1.0, lite::gl::COLOR_BUFFER | lite::gl::DEPTH_BUFFER);

        int width, height;
        lite::Window::getCurrent()->getSize(&width, &height);

        texture.bind(0);
        texture2.bind(1);
        program->use();

        camera.update(width, height);

        for (int x = -1; x < 4; ++x) {
            for (int y = 0; y < 3; ++y) {
                glm::mat4 proj = camera.getProjection();
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(x, 0, y));
                program->getUniform("view").setMatrix(camera.view, false);
                projectionUniform.setMatrix(proj, false);
                modelUniform.setMatrix(model, false);

                vao->use();
                gl::drawArrays(lite::gl::TRIANGLE, 0, 36);
            }
        }
    }

public:
    ~TestApp() {
        delete vbo;
        delete vao;
        delete ebo;
        delete program;
    }
};

int main() {
    lite::init();
    lite::DesktopApplication(new TestApp, 800, 480, "lite engine").start();
    lite::terminate();
    return 0;
}
