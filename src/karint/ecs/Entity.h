#pragma once

#include <vector>
#include "Component.h"

namespace karint {
    class Entity {
    private:
        int componentsBits = 0;
        unsigned long locationBits = 0;
        char nextComponentLocation = 0;

        std::vector<Component*> components;
    public:
        /** add component to the entity **/
        void add(Component *component);

        /** return true if the entity has the component else return false **/
        bool has(int componentId) const;

        Component* operator  [](int id);

        template<class T>
        inline T* get() {
            return static_cast<T*>(operator[](T::ecsId));
        }
    };
}

