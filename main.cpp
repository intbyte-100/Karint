#include <iostream>
#include <lite/desktop/DesktopApplication.h>
#include <lite/desktop/lite.h>
#include <lite/graphic/ElementBufferObject.h>
#include <lite/graphic/ShaderProgram.h>
#include <lite/graphic/VertexAttributeObject.h>
#include <lite/graphic/VertexBufferObject.h>
#include <lite/graphic/gl.h>

const char *vertex = "#version 330 core\n"
                     "layout (location = 0) in vec3 aPos;\n"
                     "void main()\n"
                     "{\n"
                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                     "}\0";

const char *fragment = "#version 330 core\n"
                       "out vec4 FragColor;\n"
                       "void main()\n"
                       "{\n"
                       "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                       "}\n\0";

class TestApp : public lite::Application
{
    lite::ShaderProgram *program;
    lite::VertexBufferObject *vbo;
    lite::VertexAttributeObject *vao;
    lite::ElementBufferObject *ebo;

    void onCreate() override
    {
        float vertices[] = {0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f};
        unsigned int indices[] = {0, 1, 3, 1, 2, 3};

        program = new lite::ShaderProgram(vertex, fragment);
        vao = new lite::VertexAttributeObject();
        vbo = new lite::VertexBufferObject(vertices, sizeof(vertices));
        ebo = new lite::ElementBufferObject(6, indices);

        vao->use();
        vbo->draw(lite::STATIC_DRAW);
        ebo->draw(lite::STATIC_DRAW);

        lite::vertexAttribute(0, 3, lite::FLOAT, false, 3 * sizeof(float), nullptr);
        lite::enableVertexAttributeArray(0);
    }

    void render() override {

        lite::clearScreen(0.5, 0.3, 0.6, 1.0, lite::COLOR_BUFFER);
        program->use();
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
    auto app = new TestApp();
    auto desktop = lite::DesktopApplication(app, 800, 480, "test");

    desktop.start();
    delete app;
    lite::dispose();
    return 0;
}
