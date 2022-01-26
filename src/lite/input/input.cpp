#include "input.h"
#include "GLFW/glfw3.h"
#include "lite/desktop/Window.h"

int lite::input::ESCAPE = GLFW_KEY_ESCAPE;
int lite::input::TAB = GLFW_KEY_TAB;
int lite::input::SPACE = GLFW_KEY_SPACE;
int lite::input::ENTER = GLFW_KEY_ENTER;

bool lite::input::isPressed(int key) {
    Window *window = Window::getCurrent();
    return window->isPressed(key);
}

std::function<void(double, double )> lite::input::mouseCallback;