// clang-format off
#include <glad/glad.h>
#include "Window.h"
#include "lite.h"
#include "lite/input/input.h"
#include <GLFW/glfw3.h>
#include <lite/util/LiteException.h>
// clang-format on

lite::Window *currentWindow;

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouseCallback(GLFWwindow* window, double x, double y){
    if(lite::input::mouseCallback)
        lite::input::mouseCallback(x, y);
}

lite::Window::Window(const std::string &title, int width, int height){
    window = glfwCreateWindow(width,height,title.c_str(), nullptr, nullptr);
    if(window == nullptr) {
        glfwTerminate();
        throw lite::LiteException("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        throw lite::LiteException("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetCursorPosCallback(window, mouseCallback);

    glViewport(0, 0, width, height);
}

void lite::Window::getSize(int *width, int *height)
{
    glfwGetWindowSize(window, width, height);
}

bool lite::Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void lite::Window::update() {
    glfwMakeContextCurrent(window);
    glfwSwapBuffers(window);
}

void lite::Window::dispose() {
    glfwDestroyWindow(window);
}

void lite::Window::close() {
    glfwSetWindowShouldClose(window, true);
}

void lite::Window::makeCurrent()
{
    currentWindow = this;
}

lite::Window *lite::Window::getCurrent()
{
    return currentWindow;
}

bool lite::Window::isPressed(int key) {
    int state = glfwGetKey(window, key);
    return state == GLFW_REPEAT || state == GLFW_PRESS;
}

float lite::Window::getDeltaTime() const {
    return deltaTime;
}

void lite::Window::hideCursor(bool mode) {
    glfwSetInputMode(window, GLFW_CURSOR, mode ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}




