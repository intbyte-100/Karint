#include <cmath>
#include <iostream>
#include <lite/desktop/DesktopApplication.h>
#include <lite/desktop/lite.h>
#include <lite/graphic/ElementBufferObject.h>
#include <lite/graphic/ShaderProgram.h>
#include <lite/graphic/VertexAttributeObject.h>
#include <lite/graphic/VertexBufferObject.h>
#include <lite/graphic/gl.h>
#include <lite/util/LiteException.h>

class TestApp : public lite::Application
{
    lite::ShaderProgram *program;
    lite::VertexBufferObject *vbo;
    lite::VertexAttributeObject *vao;
    lite::ElementBufferObject *ebo;

    void onCreate() override
    {
        float vertices[] = {0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f};
        unsigned int indices[] = {0, 1, 3, 1, 2, 3};

        program = lite::ShaderProgram::load("triangle.vert", "triangle.frag");
        vao = new lite::VertexAttributeObject();
        vbo = new lite::VertexBufferObject(vertices, sizeof(vertices));
        ebo = new lite::ElementBufferObject(6, indices);

        vao->use();
        vbo->draw(lite::STATIC_DRAW);
        ebo->draw(lite::STATIC_DRAW);

        lite::vertexAttribute(0, 3, lite::FLOAT, false, 6 * sizeof(float), nullptr);
        lite::enableVertexAttributeArray(0);
        lite::vertexAttribute(1, 3, lite::FLOAT, false, 6 * sizeof(float), (void *) (3 * sizeof(float)));
        lite::enableVertexAttributeArray(1);
    }

    void render() override
    {
        lite::clearScreen(0.5, 0.3, 0.6, 1.0, lite::COLOR_BUFFER);
        program->use();
        float color = sin(glfwGetTime()) / 2.0f + 0.5f;
        auto uColor = program->getUniform("uColor");
        uColor.setFloat(color);
        vao->use();
        lite::drawArrays(lite::TRIANGLE, 0, 3);
    }

public:
    ~TestApp()
    {
        delete vbo;
        delete vao;
        delete ebo;
        delete program;
    }
};

int main()
{
    lite::init();
    TestApp *app = new TestApp;
    lite::DesktopApplication(app, 800, 480, "test").start();
    delete app;
    lite::terminate();
    return 0;
}
