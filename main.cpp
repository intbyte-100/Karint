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
#include "lite/input/input.h"
#include "lite/graphic/Renderable.h"
#include "lite/graphic/Renderer.h"


using namespace lite;

class TestApp : public lite::Application {
    float lastX = 400, lastY = 300;
    bool firstMouse = true;
    float yaw   = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    float pitch =  0.0f;
    lite::ShaderProgram *program;
    lite::Texture texture;
    lite::Texture texture2;
    lite::PerspectiveCamera camera;
    lite::Renderable renderable;
    lite::Renderer renderer;

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

        input::mouseCallback = [this](double x, double y){
            float xpos = static_cast<float>(x);
            float ypos = static_cast<float>(y);

            if (firstMouse)
            {
                lastX = xpos;
                lastY = ypos;
                firstMouse = false;
            }

            float xoffset = xpos - lastX;
            float yoffset = lastY - ypos;
            lastX = xpos;
            lastY = ypos;

            float sensitivity = 0.1f;
            xoffset *= sensitivity;
            yoffset *= sensitivity;

            yaw += xoffset;
            pitch += yoffset;

            if (pitch > 89.0f)
                pitch = 89.0f;
            if (pitch < -89.0f)
                pitch = -89.0f;

            glm::vec3 front;
            front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
            front.y = sin(glm::radians(pitch));
            front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            camera.direction = glm::normalize(front);
        };
    }

    void render() override {

        glm::vec3 move(0);
        glm::vec3 velocity(3);

        if(input::isPressed(input::ESCAPE))
            Window::getCurrent()->close();
        if (input::isPressed('W'))
            move += velocity * Window::getCurrent()->getDeltaTime() * camera.direction;
        else if(input::isPressed('S'))
            move -= velocity * Window::getCurrent()->getDeltaTime() * camera.direction;
        if(input::isPressed('A')) {
            velocity *= -glm::cross(camera.direction, glm::vec3(0, 1, 0));
            move += velocity * Window::getCurrent()->getDeltaTime();
        }
        else if(input::isPressed('D')) {
            velocity *= glm::cross(camera.direction, glm::vec3(0, 1, 0));
            move += velocity * Window::getCurrent()->getDeltaTime();
        }
        move.y = 0;
        camera.position += move ;


        gl::enable(gl::DEPTH_TEST);
        gl::clearScreen(135 / 255.0f, 206 / 255.0f, 235 / 255.0f, 1.0, gl::COLOR_BUFFER | gl::DEPTH_BUFFER);

        int width, height;
        lite::Window::getCurrent()->getSize(&width, &height);
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
    lite::init();
    lite::DesktopApplication(new TestApp, 800, 600, "lite engine").start();
    lite::terminate();
    return 0;
}
