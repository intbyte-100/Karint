#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <lite/util/LiteException.h>
#include "Window.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

lite::Window::Window(const std::string &title, int width, int height){
    window = glfwCreateWindow(width,height,title.c_str(), nullptr, nullptr);
    if(window == nullptr) {
        glfwTerminate();
        throw lite::LiteException("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwTerminate();
        throw lite::LiteException("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, width, height);

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
    dispose();
}

bool lite::Window::isPressed(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}


