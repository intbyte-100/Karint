#pragma once

namespace lite {
    class ElementBufferObject
    {
    private:
        unsigned int id;
        unsigned int indicesCount = 0;
        unsigned int *indices;

    public:
        ElementBufferObject(unsigned int size, unsigned int *indices);
        void setIndices(unsigned int size, unsigned int *indices);
        void draw(unsigned int type);
    };
} // namespace lite
