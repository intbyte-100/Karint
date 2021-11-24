#include "ShaderProgram.h"
#include <glad/glad.h>
#include <lite/util/LiteException.h>

lite::ShaderProgram::ShaderProgram(const char *vertex, const char *fragment)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::string message = "Error: cannot compile vertex shader: ";
        message.append(infoLog);
        throw lite::LiteException(message);
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::string message = "Error: cannot compile fragment shader: ";
        throw lite::LiteException(message);
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::string message = "Error: cannot link shader program: ";
        message.append(infoLog);
        throw lite::LiteException(message);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

lite::Uniform lite::ShaderProgram::getUniform(const char *name)
{
    Uniform uniform;
    uniform.id = glGetUniformLocation(shaderProgram, name);
    return uniform;
}

void lite::ShaderProgram::dispose()
{
    glDeleteProgram(shaderProgram);
}

void lite::ShaderProgram::use()
{
    glUseProgram(shaderProgram);
}

lite::ShaderProgram::~ShaderProgram()
{
    dispose();
}
