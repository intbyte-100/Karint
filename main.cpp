#include "glad/glad.h"
#include "glm/glm.hpp"
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <lite/desktop/DesktopApplication.h>
#include <lite/desktop/lite.h>
#include <lite/graphic/ElementBufferObject.h>
#include <lite/graphic/ShaderProgram.h>
#include <lite/graphic/Texture.h>
#include <lite/graphic/VertexAttributeObject.h>
#include <lite/graphic/VertexBufferObject.h>
#include <lite/graphic/attribute/AttributeArray.h>
#include <lite/graphic/gl.h>
#include <lite/util/LiteException.h>
#include <unistd.h>

class TestApp : public lite::Application
{
    lite::ShaderProgram *program;
    lite::VertexBufferObject *vbo;
    lite::VertexAttributeObject *vao;
    lite::ElementBufferObject *ebo;
    lite::Texture *texture = nullptr;
    lite::Uniform transform;

    void onCreate() override
    {
        //float vertices[] = {0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f};
        float vertices[] = {
            // positions          // texture coords
            0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // top right
            0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
            -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
        };
        unsigned int indices[] = {0, 1, 3, 1, 2, 3};

        program = lite::ShaderProgram::load("triangle.vert", "triangle.frag");
        vao = new lite::VertexAttributeObject();
        vbo = new lite::VertexBufferObject(vertices, sizeof(vertices));
        ebo = new lite::ElementBufferObject(6, indices);

        vao->use();
        vbo->draw(lite::STATIC_DRAW);
        ebo->draw(lite::STATIC_DRAW);

        lite::AttributeArray attributeArray;

        attributeArray.add(lite::POSITION_ATTRIBUTE);
        attributeArray.add(lite::TEXTURE_2D_ATTRIBUTE);

        attributeArray.enable();

        texture = lite::Texture::load("wall.jpg");
        transform = program->getUniform("transform");
    }

    void render() override
    {
        lite::clearScreen(0.5, 0.3, 0.6, 1.0, lite::COLOR_BUFFER);

        texture->bind();
        program->use();

        glm::mat4 trans = glm::mat4(1.0f);

        trans = glm::rotate(trans, (float) glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        glUniformMatrix4fv(transform.id, 1, false, glm::value_ptr(trans));

        vao->use();
        lite::drawElements(lite::TRIANGLE, 6, lite::UNSIGNED_INT, 0);
        usleep(16000);
    }

public:
    ~TestApp()
    {
        delete vbo;
        delete vao;
        delete ebo;
        delete program;
        delete texture;
    }
};

int main()
{
    lite::init();
    TestApp *app = new TestApp;
    lite::DesktopApplication(app, 800, 480, "lite engine").start();
    delete app;
    lite::terminate();
    return 0;
}
