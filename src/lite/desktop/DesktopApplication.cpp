#include "DesktopApplication.h"
#include "lite.h"
#include <iostream>

lite::DesktopApplication::DesktopApplication(Application *application, int width, int height, std::string title) {
    window = new Window(title, width, height);
    this->application = application;
}

lite::DesktopApplication::~DesktopApplication()
{
    window->close();
    delete window;
    delete application;
}

bool lite::DesktopApplication::shouldTerminate() {
    return window->shouldClose();
}

void lite::DesktopApplication::start() {
    application->onCreate();
    while (!shouldTerminate()){
        float currentTime = glfwGetTime();
        window->deltaTime = currentTime - window->lastTime;
        window->lastTime = currentTime;
        window->makeCurrent();
        application->render();
        lite::update();
        window->update();
        std::flush(std::cout);
    }
}

