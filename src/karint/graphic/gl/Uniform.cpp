#include "Uniform.h"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

void karint::Uniform::setFloat(float r, float g, float b, float a)
{
    glUniform4f(id, r, g, b, a);
}

void karint::Uniform::setFloat(float r, float g, float b)
{
    glUniform3f(id, r, g, b);
}

void karint::Uniform::setFloat(float x, float y)
{
    glUniform2f(id, x, y);
}

void karint::Uniform::setFloat(float value)
{
    glUniform1f(id, value);
}

void karint::Uniform::setBool(bool value)
{
    glUniform1i(id, (int) value);
}

void karint::Uniform::setInt(int value)
{
    glUniform1i(id, value);
}

void karint::Uniform::setMatrix(glm::mat4 &matrix, bool transpose)
{
    glUniformMatrix4fv(id, 1, transpose, glm::value_ptr(matrix));
}

void karint::Uniform::setVec3(glm::vec3 &vector) {
    glUniform3f(id, vector.x, vector.y, vector.z);
}

karint::Uniform::Uniform(int id) {
    this->id = id;
}
