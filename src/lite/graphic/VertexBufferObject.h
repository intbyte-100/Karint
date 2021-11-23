#ifndef LITEENGINE_VERTEXBUFFEROBJECT_H
#define LITEENGINE_VERTEXBUFFEROBJECT_H

#include "BufferObject.h"

namespace lite {
    class VertexBufferObject: public BufferObject{
    private:
        unsigned int vbo;

    public:
        ~VertexBufferObject();
        int size;
        float *vertices;
        VertexBufferObject(float *vertices, int size);
        void staticDraw() override;
        void dynamicDraw() override;
        void streamDraw() override;
        void dispose();
    };
}


#endif
