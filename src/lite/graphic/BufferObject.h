#ifndef LITEENGINE_BUFFEROBJECT_H
#define LITEENGINE_BUFFEROBJECT_H


namespace lite {
    class BufferObject {
    protected:
        float *vertices;
    public:
        int size;
        virtual void staticDraw() = 0;
        virtual void dynamicDraw() = 0;
        virtual void streamDraw() = 0;
    };
}


#endif //LITEENGINE_BUFFEROBJECT_H
