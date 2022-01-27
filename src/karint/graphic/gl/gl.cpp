#include <sstream>
#include "gl.h"
#include "glad/glad.h"

const int karint::gl::COLOR_BUFFER = GL_COLOR_BUFFER_BIT;
const int karint::gl::DEPTH_BUFFER = GL_DEPTH_BUFFER_BIT;
const int karint::gl::DEPTH_TEST = GL_DEPTH_TEST;
const int karint::gl::FLOAT = GL_FLOAT;
const int karint::gl::DOUBLE = GL_DOUBLE;
const int karint::gl::BYTE = GL_BYTE;
const int karint::gl::UNSIGNED_BYTE = GL_UNSIGNED_BYTE;
const int karint::gl::SHORT = GL_SHORT;
const int karint::gl::UNSIGNED_SHORT = GL_UNSIGNED_SHORT;
const int karint::gl::INT = GL_INT;
const int karint::gl::UNSIGNED_INT = GL_UNSIGNED_INT;


const int karint::gl::TRIANGLE = GL_TRIANGLES;
const int karint::gl::POINT = GL_POINT;
const int karint::gl::LINE = GL_LINE;

const unsigned int karint::gl::STATIC_DRAW = GL_STATIC_DRAW;
const unsigned int karint::gl::DYNAMIC_DRAW = GL_DYNAMIC_DRAW;
const unsigned int karint::gl::STREAM_DRAW = GL_STREAM_DRAW;

const int karint::gl::TEXTURE_WRAP_X = GL_TEXTURE_WRAP_S;
const int karint::gl::TEXTURE_WRAP_Y = GL_TEXTURE_WRAP_T;
const int karint::gl::TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER;
const int karint::gl::TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER;

const int karint::gl::REPEAT = GL_REPEAT;
const int karint::gl::MIRRORED_REPEAT = GL_MIRRORED_REPEAT;
const int karint::gl::CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE;
const int karint::gl::CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER;

const int karint::gl::LINEAR = GL_LINEAR;
const int karint::gl::NEAREST = GL_NEAREST;
const int karint::gl::LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR;
const int karint::gl::LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST;
const int karint::gl::NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR;
const int karint::gl::NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST;


void karint::gl::clearScreen(float r, float g, float b, float a, int buffers) {
    glClearColor(r, g, b, a);
    glClear(buffers);
}

void karint::gl::drawArrays(int type, int first, int count) {
    glDrawArrays(type, first, count);
}

void karint::gl::drawElements(int type, int count, int indecesType, const void *offset) {
    glDrawElements(type, count, indecesType, offset);
}

void karint::gl::activeTexture(char index) {
    glActiveTexture(GL_TEXTURE0 + index);
}

void karint::gl::enable(int option) {
    glEnable(option);
}

std::string karint::gl::getBackendInfo() {
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
