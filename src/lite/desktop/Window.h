#include <string>
#include <GLFW/glfw3.h>

#ifndef LITEENGINE_WINDOW_H
#define LITEENGINE_WINDOW_H

namespace lite {
    class Window {
    private:
        GLFWwindow *window;
    public:
        Window(const std::string&, int  width, int height);
        void getSize(int *width, int *height);
        bool isPressed(int key);
        bool shouldClose();
        void update();
        void dispose();
        void close();
        void makeCurrent();
        static Window *getCurrent();
    };
}

#endif //LITEENGINE_WINDOW_H
