#include <lite/desktop/DesktopApplication.h>
#include <lite/desktop/lite.h>
#include <lite/graphic/VertexBufferObject.h>
#include <lite/graphic/VertexAttributeObject.h>
#include <lite/graphic/ShaderProgram.h>
#include <lite/graphic/gl.h>
#include <iostream>


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


class TestApp : public lite::Application {

    lite::ShaderProgram *program;
    lite::VertexBufferObject *vbo;
    lite::VertexAttributeObject *vao;

    void onCreate() override {
        float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f, 0.5f, 0.0f
        };

        program = new lite::ShaderProgram(vertex, fragment);
        vao = new lite::VertexAttributeObject();
        vbo = new lite::VertexBufferObject(vertices, sizeof(vertices));

        vao->use();
        vbo->staticDraw();
        lite::vertexAttribute(0, 3, lite::FLOAT, false, 3 * sizeof(float), nullptr);
        lite::enableVertexAttributeArray(0);

    }

    void render() override {

        lite::clearScreen(0.5, 0.3, 0.6, 1.0, lite::COLOR_BUFFER);
        program->use();
        vao->use();
        lite::drawArrays(lite::TRIANGLE, 0, 3);
    }

    void dispose() override {
        delete vbo;
        delete vao;
        delete program;
    }
};


int main() {
    lite::init();
    auto desktop = lite::DesktopApplication(new TestApp(), 800, 480, "test");
    desktop.start();
    desktop.terminate();
    return 0;
}
