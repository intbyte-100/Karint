#include "lite.h"
#include <cstdio>
#include <memory>
#include <string>
#include <array>

int sessionType = 0;

void lite::terminate()
{
    glfwTerminate();
}

void lite::update() {
    glfwPollEvents();
}

void lite::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_ALPHA_BITS, 0);
    glfwSwapInterval(1);
}

