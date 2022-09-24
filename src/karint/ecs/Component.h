#pragma once


#define ECS_COMPONENT_HEADER public: static int ecsId; \
    public: static void setEcsId(int id);  \
    virtual int getEcsId() const;
#define DEFINE_ECS_COMPONENT(component) int component::ecsId = -1; \
    void component::setEcsId(int id) {                             \
        ecsId = id;                                                \
    }                                                              \
    int component::getEcsId() const {                              \
        return ecsId;                                              \
    }
namespace karint {
    class Component {

    public:
        virtual int getEcsId() const = 0;
    };
}



