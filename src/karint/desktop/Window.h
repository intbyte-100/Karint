#include <string>
#include <GLFW/glfw3.h>

#ifndef karintENGINE_WINDOW_H
#define karintENGINE_WINDOW_H

namespace karint {
    class DesktopApplication;
    class Window {
        friend DesktopApplication;
    private:
        GLFWwindow *window;
        float deltaTime;
        float lastTime;
    public:
        Window(const std::string&, int  width, int height);
        void getSize(int *width, int *height);
        bool isPressed(int key);
        bool shouldClose();
        void update();
        void dispose();
        void close();
        void makeCurrent();
        float getDeltaTime() const;
        void hideCursor(bool mode);
        static Window *getCurrent();
    };
}

#endif //karintENGINE_WINDOW_H
