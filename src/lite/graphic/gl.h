#pragma once

namespace lite {

    void clearScreen(float r, float g, float b, float a, int buffer);
    void vertexAttribute(int index, int size, int type, bool normalized, int stride, const void *pointer);
    void enableVertexAttributeArray(int index);
    void drawArrays(int type, int first, int count);
    void drawElements(int type, int count, int indecesType, const void *offset);
    void activeTexture(char index);
    void enable(int option);

    extern const int COLOR_BUFFER;
    extern const int DEPTH_BUFFER;
    extern const int DEPTH_TEST;

    extern const int DOUBLE;
    extern const int BYTE;
    extern const int UNSIGNED_BYTE;
    extern const int SHORT;
    extern const int UNSIGNED_SHORT;
    extern const int INT;
    extern const int UNSIGNED_INT;
    extern const int FLOAT;

    extern const int POINT;
    extern const int LINE;
    extern const int TRIANGLE;

    extern const unsigned int STATIC_DRAW;
    extern const unsigned int DYNAMIC_DRAW;
    extern const unsigned int STREAM_DRAW;

    extern const int TEXTURE_WRAP_X;
    extern const int TEXTURE_WRAP_Y;
    extern const int TEXTURE_MIN_FILTER;
    extern const int TEXTURE_MAG_FILTER;

    extern const int REPEAT;
    extern const int MIRRORED_REPEAT;
    extern const int CLAMP_TO_EDGE;
    extern const int CLAMP_TO_BORDER;

    extern const int LINEAR;
    extern const int NEAREST;
    extern const int NEAREST_MIPMAP_NEAREST;
    extern const int LINEAR_MIPMAP_NEAREST;
    extern const int NEAREST_MIPMAP_LINEAR;
    extern const int LINEAR_MIPMAP_LINEAR;
}
