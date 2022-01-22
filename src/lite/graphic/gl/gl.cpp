#include <sstream>
#include "gl.h"
#include "glad/glad.h"

const int lite::gl::COLOR_BUFFER = GL_COLOR_BUFFER_BIT;
const int lite::gl::DEPTH_BUFFER = GL_DEPTH_BUFFER_BIT;
const int lite::gl::DEPTH_TEST = GL_DEPTH_TEST;
const int lite::gl::FLOAT = GL_FLOAT;
const int lite::gl::DOUBLE = GL_DOUBLE;
const int lite::gl::BYTE = GL_BYTE;
const int lite::gl::UNSIGNED_BYTE = GL_UNSIGNED_BYTE;
const int lite::gl::SHORT = GL_SHORT;
const int lite::gl::UNSIGNED_SHORT = GL_UNSIGNED_SHORT;
const int lite::gl::INT = GL_INT;
const int lite::gl::UNSIGNED_INT = GL_UNSIGNED_INT;


const int lite::gl::TRIANGLE = GL_TRIANGLES;
const int lite::gl::POINT = GL_POINT;
const int lite::gl::LINE = GL_LINE;

const unsigned int lite::gl::STATIC_DRAW = GL_STATIC_DRAW;
const unsigned int lite::gl::DYNAMIC_DRAW = GL_DYNAMIC_DRAW;
const unsigned int lite::gl::STREAM_DRAW = GL_STREAM_DRAW;

const int lite::gl::TEXTURE_WRAP_X = GL_TEXTURE_WRAP_S;
const int lite::gl::TEXTURE_WRAP_Y = GL_TEXTURE_WRAP_T;
const int lite::gl::TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER;
const int lite::gl::TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER;

const int lite::gl::REPEAT = GL_REPEAT;
const int lite::gl::MIRRORED_REPEAT = GL_MIRRORED_REPEAT;
const int lite::gl::CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE;
const int lite::gl::CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER;

const int lite::gl::LINEAR = GL_LINEAR;
const int lite::gl::NEAREST = GL_NEAREST;
const int lite::gl::LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR;
const int lite::gl::LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST;
const int lite::gl::NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR;
const int lite::gl::NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST;


void lite::gl::clearScreen(float r, float g, float b, float a, int buffers) {
    glClearColor(r, g, b, a);
    glClear(buffers);
}

void lite::gl::drawArrays(int type, int first, int count) {
    glDrawArrays(type, first, count);
}

void lite::gl::drawElements(int type, int count, int indecesType, const void *offset) {
    glDrawElements(type, count, indecesType, offset);
}

void lite::gl::activeTexture(char index) {
    glActiveTexture(GL_TEXTURE0 + index);
}

void lite::gl::enable(int option) {
    glEnable(option);
}

std::string lite::gl::getBackendInfo() {
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *vendor = glGetString(GL_VENDOR);
    const GLubyte *version = glGetString(GL_VERSION);
    const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    std::ostringstream string;
    string << "OpenGL Vendor: " << vendor << "\n";
    string << "OpenGL Renderer: " << renderer << "\n";
    string << "OpenGL Version: " << version << "\n";
    string << "GLSL version: " << glslVersion;

    return string.str();
}
