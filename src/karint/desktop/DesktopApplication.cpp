#include "DesktopApplication.h"
#include "karint.h"
#include "../util/logger.h"
#include "karint/util/FileException.h"
#include <iostream>

karint::DesktopApplication::DesktopApplication(Application *application, int width, int height, std::string title) {
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    window = new Window(title, mode->width, mode->height);
    this->application = application;
    std::cout << "karint engine has been inited" << std::endl;
}

karint::DesktopApplication::~DesktopApplication()
{
    window->close();
    delete window;
    delete application;
}

bool karint::DesktopApplication::shouldTerminate() {
    return window->shouldClose();
}


void karint::DesktopApplication::start() {
    try {
        window->makeCurrent();
        application->onCreate();
        while (!shouldTerminate()) {
            float currentTime = glfwGetTime();
            window->deltaTime = currentTime - window->lastTime;
            window->lastTime = currentTime;
            application->render();
            karint::update();
            window->update();
            std::flush(std::cout);
        }
    } catch(std::exception &e) {
        std::string text;
        text+=std::current_exception().__cxa_exception_type()->name();
        text+=": ";
        text+=e.what();
        logger::fatalError("Critical error was occurred", text.c_str());
    } catch (...) {
        logger::fatalError("Critical error was occurred", std::current_exception().__cxa_exception_type()->name());
    }
}

