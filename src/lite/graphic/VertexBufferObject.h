#ifndef LITEENGINE_VERTEXBUFFEROBJECT_H
#define LITEENGINE_VERTEXBUFFEROBJECT_H

namespace lite {
    class VertexBufferObject
    {
    private:
        unsigned int vbo;

    public:
        ~VertexBufferObject();
        int size;
        float *vertices;
        VertexBufferObject(float *vertices, int size);
        void draw(unsigned int type);
        void dispose();
    };
}


#endif
