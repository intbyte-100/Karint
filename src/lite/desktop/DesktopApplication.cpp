#include "DesktopApplication.h"
#include "lite.h"
#include <iostream>

lite::DesktopApplication::DesktopApplication(Application *application, int width, int height, std::string title) {
    window = new Window(title, width, height);
    this->application = application;
    std::cout << "Lite engine has been inited" << std::endl;
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
    window->makeCurrent();
    application->onCreate();
    while (!shouldTerminate()){
        float currentTime = glfwGetTime();
        window->deltaTime = currentTime - window->lastTime;
        window->lastTime = currentTime;
        application->render();
        lite::update();
        window->update();
        std::flush(std::cout);
    }
}

