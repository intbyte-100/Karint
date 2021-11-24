#include "gl.h"
#include <glad/glad.h>


const int lite::COLOR_BUFFER = GL_COLOR_BUFFER_BIT;
const int lite::DEPTH_BUFFER = GL_DEPTH_BUFFER_BIT;
const int lite::FLOAT = GL_FLOAT;
const int lite::DOUBLE = GL_DOUBLE;
const int lite::BYTE = GL_BYTE;
const int lite::UNSIGNED_BYTE = GL_UNSIGNED_BYTE;
const int lite::SHORT = GL_SHORT;
const int lite::UNSIGNED_SHORT = GL_UNSIGNED_SHORT;
const int lite::INT = GL_INT;
const int lite::UNSIGNED_INT = GL_UNSIGNED_INT;


const int lite::TRIANGLE = GL_TRIANGLES;
const int lite::POINT = GL_POINT;
const int lite::LINE = GL_LINE;

const unsigned int lite::STATIC_DRAW = GL_STATIC_DRAW;
const unsigned int lite::DYNAMIC_DRAW = GL_DYNAMIC_DRAW;
const unsigned int lite::STREAM_DRAW = GL_STREAM_DRAW;

void lite::clearScreen(float r, float g, float b, float a, int buffers){
    glClearColor(r,g,b,a);
    glClear(buffers);
}

void lite::vertexAttribute(int index, int size, int type, bool normalized, int stride, const void *pointer) {
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, pointer);
}

void lite::enableVertexAttributeArray(int index) {
    glEnableVertexAttribArray(index);
}

void lite::drawArrays(int type, int first, int count) {
    glDrawArrays(type, first, count);
}

void lite::drawElements(int type, int count, int indecesType, const void *offset)
{
    glDrawElements(type, count, indecesType, offset);
}
