#include "DesktopApplication.h"
#include "karint.h"
#include "../util/logger.h"
#include "karint/util/FileException.h"
#include <iostream>

karint::DesktopApplication::DesktopApplication(Application *application, std::string title, int width, int height, bool fullscreen ) {
    window = new Window(title, width, height, fullscreen);
    this->application = application;
    karint_debug_log("initialisation", "initialisation is finished");
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
        glfwTerminate();
        logger::fatalError("Critical error", text.c_str());

    } catch (...) {
        window->close();
        logger::fatalError("Critical error", std::current_exception().__cxa_exception_type()->name());
    }
}

