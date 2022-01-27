#ifndef karintENGINE_VERTEXBUFFEROBJECT_H
#define karintENGINE_VERTEXBUFFEROBJECT_H

namespace karint {
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
