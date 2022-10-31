#include "ShaderProgram.h"
#include "glad/glad.h"
#include "karint/util/KarintException.h"
#include "karint/util/File.h"
#include "karint/util/logger.h"

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
    karint_debug_log("ShaderProgram", "the program is created");
}

karint::Uniform karint::ShaderProgram::getUniform(const char *name)
{
    return Uniform(glGetUniformLocation(shaderProgram, name));
}

void karint::ShaderProgram::dispose()
{
    glDeleteProgram(shaderProgram);
}

void karint::ShaderProgram::use()
{
    glUseProgram(shaderProgram);
}

karint::ShaderProgram karint::ShaderProgram::load(const std::string &vertex, const std::string &fragment)
{
    karint_debug_log("ShaderProgram", "creating a program with fragment '" << fragment << "' and vertex '" << vertex << "' shaders");
    std::string vertexSource = File::load(vertex).read();
    std::string fragmentSource = File::load(fragment).read();

    return {vertexSource.c_str(), fragmentSource.c_str()};
}


unsigned int karint::ShaderProgram::getUniformBlockIndex(const char *name) const {
    return glGetUniformBlockIndex(shaderProgram, name);
}

void karint::ShaderProgram::uniformBlockBinding(unsigned int index, unsigned int binding) const {
    glUniformBlockBinding(shaderProgram, index, binding);
}

void karint::ShaderProgram::uniformBlockBinding(const char* name, unsigned int binding) const {
    glUniformBlockBinding(shaderProgram, glGetUniformBlockIndex(shaderProgram, name), binding);
}