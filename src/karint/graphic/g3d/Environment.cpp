#include "Environment.h"

void karint::Environment::resetAmbient() {
    ambient = glm::vec3(1);
}

void karint::Environment::addAmbient(glm::vec3 light) {
    ambient*=light;
}
