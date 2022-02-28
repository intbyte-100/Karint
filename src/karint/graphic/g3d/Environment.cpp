#include "Environment.h"

void karint::Environment::resetAmbient() {
    ambient = glm::vec3(1);
}

void karint::Environment::addAmbient(glm::vec3 light) {
    ambient*=light;
}

void karint::Environment::setDiffuseLight(glm::vec3 position, glm::vec3 color) {
    this->diffuseLightPosition = position;
    this->diffuseColor = color;
}
