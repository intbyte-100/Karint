#ifndef LITEENGINE_VERTEXBUFFEROBJECT_H
#define LITEENGINE_VERTEXBUFFEROBJECT_H

namespace lite {
    class VertexBufferObject
    {
    public:
        unsigned int id;
        ~VertexBufferObject();
        void create();
        void setVertices(float *vertices, int count, unsigned int type);
        void dispose();
    };
}

#endif
