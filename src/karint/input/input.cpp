#include "input.h"
#include "GLFW/glfw3.h"
#include "karint/desktop/Window.h"

int karint::input::ESCAPE = GLFW_KEY_ESCAPE;
int karint::input::TAB = GLFW_KEY_TAB;
int karint::input::SPACE = GLFW_KEY_SPACE;
int karint::input::ENTER = GLFW_KEY_ENTER;
int karint::input::SHIFT = GLFW_KEY_LEFT_SHIFT;

bool karint::input::isPressed(int key) {
    Window *window = Window::getCurrent();
    return window->isPressed(key);
}

std::function<void(double, double )> karint::input::mouseCallback;