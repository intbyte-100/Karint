#ifndef LITEENGINE_VERTEXATTRIBUTEOBJECT_H
#define LITEENGINE_VERTEXATTRIBUTEOBJECT_H

namespace lite{
    class VertexAttributeObject {
    private:
        unsigned int vao;
    public:
        ~VertexAttributeObject();
        VertexAttributeObject();
        void use();
        void dispose();
    };
}


#endif //LITEENGINE_VERTEXATTRIBUTEOBJECT_H
