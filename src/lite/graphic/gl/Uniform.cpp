#include "Uniform.h"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

void lite::Uniform::setFloat(float r, float g, float b, float a)
{
    glUniform4f(id, r, g, b, a);
}

void lite::Uniform::setFloat(float r, float g, float b)
{
    glUniform3f(id, r, g, b);
}

void lite::Uniform::setFloat(float x, float y)
{
    glUniform2f(id, x, y);
}

void lite::Uniform::setFloat(float value)
{
    glUniform1f(id, value);
}

void lite::Uniform::setBool(bool value)
{
    glUniform1i(id, (int) value);
}

void lite::Uniform::setInt(int value)
{
    glUniform1i(id, value);
}

void lite::Uniform::setMatrix(glm::mat4 &matrix, bool transpose)
{
    glUniformMatrix4fv(id, 1, transpose, glm::value_ptr(matrix));
}
