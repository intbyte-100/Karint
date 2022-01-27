// clang-format off
#include <glad/glad.h>
#include "Window.h"
#include "karint.h"
#include "karint//input/input.h"
#include <GLFW/glfw3.h>
#include <karint/util/KarintException.h>
// clang-format on

karint::Window *currentWindow;

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouseCallback(GLFWwindow* window, double x, double y){
    if(karint::input::mouseCallback)
        karint::input::mouseCallback(x, y);
}

karint::Window::Window(const std::string &title, int width, int height){
    window = glfwCreateWindow(width,height,title.c_str(), nullptr, nullptr);
    if(window == nullptr) {
        glfwTerminate();
        throw karint::KarintException("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        throw karint::KarintException("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetCursorPosCallback(window, mouseCallback);

    glViewport(0, 0, width, height);
}

void karint::Window::getSize(int *width, int *height)
{
    glfwGetWindowSize(window, width, height);
}

bool karint::Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void karint::Window::update() {
    glfwMakeContextCurrent(window);
    glfwSwapBuffers(window);
}

void karint::Window::dispose() {
    glfwDestroyWindow(window);
}

void karint::Window::close() {
    glfwSetWindowShouldClose(window, true);
}

void karint::Window::makeCurrent()
{
    currentWindow = this;
}

karint::Window *karint::Window::getCurrent()
{
    return currentWindow;
}

bool karint::Window::isPressed(int key) {
    int state = glfwGetKey(window, key);
    return state == GLFW_REPEAT || state == GLFW_PRESS;
}

float karint::Window::getDeltaTime() const {
    return deltaTime;
}

void karint::Window::hideCursor(bool mode) {
    glfwSetInputMode(window, GLFW_CURSOR, mode ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}




