#include "Window.h"
#include "lite/Application.h"

#ifndef LITEENGINE_DESKTOPAPPLICATION_H
#define LITEENGINE_DESKTOPAPPLICATION_H


namespace lite {
    class DesktopApplication {
    private:
        Application *application;
        Window *window;
    public:
        DesktopApplication(Application *application, int width, int height, std::string title);
        bool shouldTerminate();
        void start();
        void terminate();
    };
}

#endif
