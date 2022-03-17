#pragma once

#include "VertexBufferObject.h"

namespace karint {
    class UniformBlockBuffer {
    private:
        unsigned int id = 0;
    public:
        void create();
        void copyData(void* source, int size) const;
        void use(int binding) const;
    };
}
