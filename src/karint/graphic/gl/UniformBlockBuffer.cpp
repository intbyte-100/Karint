#include "UniformBlockBuffer.h"
#include "glad/glad.h"

void karint::UniformBlockBuffer::create() {
    glGenBuffers(1, &id);
}

void karint::UniformBlockBuffer::copyData(void *source, int size) const {
    auto ptr = (float*) source;
    glBindBuffer(GL_UNIFORM_BUFFER,id);
    glBufferData(GL_UNIFORM_BUFFER, size, source, GL_DYNAMIC_DRAW);
}

void karint::UniformBlockBuffer::use(int binding) const {
    glBindBufferBase(GL_UNIFORM_BUFFER, binding, id);
}
