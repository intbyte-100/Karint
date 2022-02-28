#ifndef karintENGINE_VERTEXBUFFEROBJECT_H
#define karintENGINE_VERTEXBUFFEROBJECT_H

namespace karint {
    class VertexBufferObject
    {
    public:
        unsigned int id;
        void create();
        void setVertices(float *vertices, int count, unsigned int type) const;
        void dispose();
    };
}

#endif
