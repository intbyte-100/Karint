#include "karint.h"
#include <cstdio>
#include <memory>
#include <string>
#include <array>

int sessionType = 0;

void karint::terminate()
{
    glfwTerminate();
}

void karint::update() {
    glfwPollEvents();
}

void karint::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CENTER_CURSOR, 1);
    glfwWindowHint(GLFW_ALPHA_BITS, 0);
    glfwSwapInterval(1);
}

