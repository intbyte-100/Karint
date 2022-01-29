#pragma once

#include <functional>

namespace karint {
    namespace input {
        extern std::function<void(double, double )> mouseCallback;
        extern int ESCAPE, TAB, SPACE, ENTER, SHIFT;
        bool isPressed(int key);
    }
}



