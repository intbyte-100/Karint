#ifndef LITEENGINE_VERTEXATTRIBUTEOBJECT_H
#define LITEENGINE_VERTEXATTRIBUTEOBJECT_H

namespace lite{
    class VertexAttributeObject {
    public:
        unsigned int id;
        ~VertexAttributeObject();
        VertexAttributeObject();
        void use();
        void dispose();
    };
}


#endif //LITEENGINE_VERTEXATTRIBUTEOBJECT_H
