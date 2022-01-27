#include <glm/gtc/matrix_transform.hpp>
#include <karint/desktop/DesktopApplication.h>
#include <karint/desktop/karint.h>
#include "karint/graphic/gl/ElementBufferObject.h"
#include "karint/graphic/gl/ShaderProgram.h"
#include "karint/graphic/gl/Texture.h"
#include "karint/graphic/gl/VertexAttributeObject.h"
#include "karint/graphic/gl/VertexBufferObject.h"
#include <iostream>
#include "karint/graphic/gl/gl.h"
#include "karint/graphic/PerspectiveCamera.h"
#include "karint/input/input.h"
#include "karint/graphic/Renderable.h"
#include "karint/graphic/Renderer.h"
#include "karint/math/math.h"
#include "karint/input/CameraController.h"


using namespace karint;

class TestApp : public karint::Application {
    karint::ShaderProgram *program;
    karint::Texture texture;
    karint::Texture texture2;
    karint::PerspectiveCamera camera;
    karint::Renderable renderable;
    karint::Renderer renderer;
    karint::CameraController controller;

    glm::vec3 finalDirection;

    void onCreate() override {
        std::cout << karint::gl::getBackendInfo() << "\n";

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

        std::vector<attribute::Attribute> array{
                attribute::POSITION,
                attribute::TEXTURE_2D
        };


        program = ShaderProgram::load("triangle.vert", "triangle.frag");

        renderable.create();
        renderable.setVertices(vertices, 180, gl::STATIC_DRAW);
        renderable.enableAttributes(array);
        renderable.triangles = 36;

        texture = Texture::load("stone.jpeg");
        texture2 = Texture::load("stone.jpeg");

        program->use();
        program->getUniform("texture1").setInt(0);
        program->getUniform("texture2").setInt(1);
        renderer.setShader(*program);

        camera = PerspectiveCamera(100, 0.1f, 45);
        camera.position = glm::vec3(1.0f, 4.0f, 6.0f);
        camera.direction = glm::vec3(1.0f, 0.0f, -1.0f);


        Window::getCurrent()->hideCursor(true);

        controller.setCamera(&camera);
        controller.smooth = 0.6f;
        input::mouseCallback = controller.getMouseCallback();
    }

    void render() override {

        controller.update();
        glm::vec2 move(0);
        glm::vec2 velocity(3);

        if(input::isPressed(input::ESCAPE))
            Window::getCurrent()->close();
        if (input::isPressed('W'))
            move += math::rotate(velocity, controller.getYaw()-90);
        else if(input::isPressed('S'))
            move -= math::rotate(velocity, controller.getYaw()-90);
        if(input::isPressed('A'))
            move -= math::rotate(velocity, controller.getYaw());
        else if(input::isPressed('D'))
            move += math::rotate(velocity, controller.getYaw());


        move*=Window::getCurrent()->getDeltaTime();
        camera.position.x += move.x;
        camera.position.z += move.y;

        gl::enable(gl::DEPTH_TEST);
        gl::clearScreen(135 / 255.0f, 206 / 255.0f, 235 / 255.0f, 1.0, gl::COLOR_BUFFER | gl::DEPTH_BUFFER);

        int width, height;
        karint::Window::getCurrent()->getSize(&width, &height);
        camera.update(width, height);

        renderable.use();
        texture.bind(0);
        texture2.bind(1);

        renderer.use(&camera);

        for (int x = -1; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                renderable.model = glm::translate(glm::mat4(1.0f), glm::vec3(x, 0, y));
                renderer.draw(&renderable);
            }
        }
    }

public:
    ~TestApp() {
        delete program;
    }
};

int main() {
    karint::init();
    karint::DesktopApplication(new TestApp, 800, 600, "karint engine").start();
    karint::terminate();
    return 0;
}
