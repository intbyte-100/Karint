#include "DesktopApplication.h"
#include "karint.h"
#include <iostream>

karint::DesktopApplication::DesktopApplication(Application *application, int width, int height, std::string title) {
    window = new Window(title, width, height);
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
    window->makeCurrent();
    application->onCreate();
    while (!shouldTerminate()){
        float currentTime = glfwGetTime();
        window->deltaTime = currentTime - window->lastTime;
        window->lastTime = currentTime;
        application->render();
        karint::update();
        window->update();
        std::flush(std::cout);
    }
}

