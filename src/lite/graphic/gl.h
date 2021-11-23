#pragma once

namespace lite {

    void clearScreen(float r, float g, float b, float a, int buffer);
    void vertexAttribute(int index, int size, int type, bool normalized, int stride, const void *pointer);
    void enableVertexAttributeArray(int index);
    void drawArrays(int type, int first, int count);

    extern const int COLOR_BUFFER;
    extern const int DEPTH_BUFFER;

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

    extern const unsigned int STATIC_DRAW, DYNAMIC_DRAW, STREAM_DRAW;

}
