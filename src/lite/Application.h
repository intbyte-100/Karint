#ifndef LITEENGINE_APPLICATION_H
#define LITEENGINE_APPLICATION_H

namespace lite {
    class Application {
    public:
        virtual void render(){};
        virtual void dispose(){};
        virtual void onCreate(){};
    };
}


#endif
