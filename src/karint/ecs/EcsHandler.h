#pragma once

namespace karint {
    class EcsHandler {
    private:
        int lastId = 0;
    public:
        int registerComponent();
        template<class T>
        inline void registerComponent(){
            T::setEcsId(registerComponent());
        }
    };
}

