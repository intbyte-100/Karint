#include "Material.h"


void karint::Material::use(int binding) {
    uniformBuffer.use(binding);
}

void karint::Material::update() {
    uniformBuffer.copyData(&this->color, sizeof(Material)- sizeof(UniformBlockBuffer));
}

void karint::Material::create() {
    uniformBuffer.create();
}

