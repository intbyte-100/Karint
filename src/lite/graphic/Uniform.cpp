#include "Uniform.h"
#include "glad/glad.h"

void lite::Uniform::uniform4f(float r, float g, float b, float a)
{
    glUniform4f(id, r, g, b, a);
}
