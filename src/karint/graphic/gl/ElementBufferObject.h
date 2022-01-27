#pragma once

namespace karint {
    class ElementBufferObject
    {
    public:
        unsigned int id;
        void setIndices(unsigned int *indices, int count,  unsigned int type);
        void create();
    };
}