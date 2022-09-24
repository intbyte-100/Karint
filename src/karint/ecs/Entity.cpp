#include "Entity.h"

void karint::Entity::add(karint::Component *component) {
    int id = component->getEcsId();
    componentsBits = componentsBits | 1 << id;
    locationBits = locationBits | components.size() << 4 * id;
    components.push_back(component);
}

bool karint::Entity::has(int componentId) const {
    return componentsBits & 1 << componentId;
}

karint::Component *karint::Entity::operator[](int id) {
    if (has(id))
        return components[(locationBits >> 4 * id) & 0xF];
    return nullptr;
}
