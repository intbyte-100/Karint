#include "ShaderProgram.h"
#include <fstream>
#include "glad/glad.h"
#include "karint/util/KarintException.h"
#include <sstream>
#include <string>

karint::ShaderProgram::ShaderProgram(const char *vertex, const char *fragment)
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
        message.append(infoLog).append("\nshader source:\n").append(vertex);

        throw karint::KarintException(message);
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::string message = "Error: cannot compile fragment shader: ";
        message.append(infoLog).append("\nshader source:\n").append(fragment);
        throw karint::KarintException(message);
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
        throw karint::KarintException(message);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

karint::Uniform karint::ShaderProgram::getUniform(const char *name)
{
    Uniform uniform;
    uniform.id = glGetUniformLocation(shaderProgram, name);
    return uniform;
}

void karint::ShaderProgram::dispose()
{
    glDeleteProgram(shaderProgram);
}

void karint::ShaderProgram::use()
{
    glUseProgram(shaderProgram);
}

karint::ShaderProgram *karint::ShaderProgram::load(const std::string &vertex, const std::string &fragment)
{
    std::ifstream file;
    std::stringstream vShaderStream, fShaderStream;

    file.open(vertex);

    vShaderStream << file.rdbuf();
    file.close();

    file.open(fragment);
    fShaderStream << file.rdbuf();
    file.close();

    return new ShaderProgram(vShaderStream.str().c_str(), fShaderStream.str().c_str());
}

karint::ShaderProgram::~ShaderProgram()
{
    dispose();
}
