#include "Window.h"
#include "karint/Application.h"

#ifndef karintENGINE_DESKTOPAPPLICATION_H
#define karintENGINE_DESKTOPAPPLICATION_H


namespace karint {
    class DesktopApplication {
    private:
        Application *application;
        Window *window;
    public:
        DesktopApplication(Application *application, std::string title, int width, int height, bool fullscreen = false);
        ~DesktopApplication();
        bool shouldTerminate();
        void start();
    };
}

#endif
