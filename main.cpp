#include <glm/gtc/matrix_transform.hpp>
#include <karint/desktop/DesktopApplication.h>
#include <karint/desktop/karint.h>
#include "karint/graphic/gl/ShaderProgram.h"
#include "karint/graphic/gl/Texture.h"
#include "karint/graphic/gl/VertexAttributeObject.h"
#include <iostream>
#include "karint/graphic/gl/gl.h"
#include "karint/graphic/PerspectiveCamera.h"
#include "karint/input/input.h"
#include "karint/graphic/Renderable.h"
#include "karint/graphic/Renderer.h"
#include "karint/math/kmath.h"
#include "karint/input/CameraController.h"
#include "karint/graphic/OrthographicCamera.h"
#include "karint/graphic/g3d/Vertex.h"
#include "vertices.h"

using namespace karint;

class TestApp : public Application {
    ShaderProgram program;
    ShaderProgram lightProgram;
    Texture texture;
    PerspectiveCamera camera;
    Environment environment;
    Renderable renderable;
    Renderer renderer;
    CameraController controller;


    void onCreate() override {
        std::cout << gl::getBackendInfo() << "\n";


        program = ShaderProgram::load("3ddefault.vert", "3ddefault.frag");
        lightProgram = ShaderProgram::load("light.vert", "light.frag");

        renderable.create();
        renderable.setVertices(&vertices[0], vertices.size(), gl::STATIC_DRAW);
        renderable.triangles = 36;

        Material material(glm::vec3(1, 1, 1));
        material.specularity = 0.5f;
        material.diffuse=1.0;
        material.create();
        material.update();

        renderable.material = material;

        texture = Texture::load("stone.jpeg");

        Vertex::enableDefaultVertexAttributes();

        program.use();
        program.getUniform("texture1").setInt(0);
        renderer.setShader(program);

        camera = PerspectiveCamera(100, 0.1f, 45);
        camera.position = glm::vec3(1.0f, 4.0f, 6.0f);


        controller.setCamera(&camera);
        controller.smooth = 0.70f;
        input::mouseCallback = controller.getMouseCallback();

        environment.addAmbient(glm::vec3(0.3));
        environment.setDiffuseLight(glm::vec3(0.0f, 2.0f, 2.0f), glm::vec3(1, 1, 1));
        renderer.setEnvironment(&environment);
    }

    void render() override {

        controller.update();
        glm::vec2 move(0);
        glm::vec2 velocity(3);

        if (input::isPressed(input::ESCAPE))
            Window::getCurrent()->close();
        if (input::isPressed('W'))
            move += math::rotate(velocity, controller.getYaw() - 90);
        else if (input::isPressed('S'))
            move -= math::rotate(velocity, controller.getYaw() - 90);
        if (input::isPressed('A'))
            move -= math::rotate(velocity, controller.getYaw());
        else if (input::isPressed('D'))
            move += math::rotate(velocity, controller.getYaw());

        if (input::isPressed(input::SHIFT))
            move *= 1.7;

        move *= Window::getCurrent()->getDeltaTime();
        camera.position.x += move.x;
        camera.position.z += move.y;

        gl::enable(gl::DEPTH_TEST);
        glm::vec3 skyColor(135 / 255.0f, 206 / 255.0f, 235 / 255.0f);
        skyColor*=0.15;
        gl::clearScreen(skyColor.x, skyColor.y, skyColor.z, 1.0, gl::COLOR_BUFFER | gl::DEPTH_BUFFER);

        int width, height;
        karint::Window::getCurrent()->getSize(&width, &height);
        camera.update(width, height);


        renderable.use();
        texture.bind(0);

        renderer.setShader(program);
        renderer.use(&camera);

        for (int x = -1; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                renderable.model = glm::translate(glm::mat4(1.0f), glm::vec3(x, 0, y));
                renderer.draw(&renderable);
            }
        }
        for (int i = 0; i < 5; ++i) {
            renderable.model = glm::translate(glm::mat4(1.0f), glm::vec3(5, i, 5));
            renderer.draw(&renderable);
        }
        renderable.model = glm::translate(glm::mat4(1),environment.diffuseLightPosition);

        renderer.setShader(lightProgram);
        renderer.use(&camera);
        renderer.draw(&renderable);
    }

public:
    ~TestApp() {
        program.dispose();
    }
};

int main() {

    karint::init();
    karint::DesktopApplication(new TestApp, "karint engine", 1280, 720, false).start();
    karint::terminate();
    return 0;
}
