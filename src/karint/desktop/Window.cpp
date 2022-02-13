// clang-format off
#include <glad/glad.h>
#include "Window.h"
#include "karint.h"
#include "karint//input/input.h"
#include <GLFW/glfw3.h>
#include <karint/util/KarintException.h>
// clang-format on

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

karint::Window *currentWindow;

bool glfwSetWindowCenter( GLFWwindow * window )
{
    if( !window )
        return false;

    int sx = 0, sy = 0;
    int px = 0, py = 0;
    int mx = 0, my = 0;
    int monitor_count = 0;
    int best_area = 0;
    int final_x = 0, final_y = 0;

    glfwGetWindowSize( window , &sx, &sy );
    glfwGetWindowPos( window , &px, &py );

    // Iterate throug all monitors
    GLFWmonitor ** m = glfwGetMonitors( &monitor_count );
    if( !m )
        return false;

    for( int j = 0; j < monitor_count ; ++j )
    {

        glfwGetMonitorPos( m[j] , &mx, &my );
        const GLFWvidmode * mode = glfwGetVideoMode( m[j] );
        if( !mode )
            continue;

        // Get intersection of two rectangles - screen and window
        int minX = MIN( mx , px );
        int minY = MAX( my , py );

        int maxX = MIN( mx+mode->width , px+sx );
        int maxY = MIN( my+mode->height , py+sy );

        // Calculate area of the intersection
        int area = MAX( maxX - minX , 0 ) * MAX( maxY - minY , 0 );

        // If its bigger than actual (window covers more space on this monitor)
        if( area > best_area )
        {
            // Calculate proper position in this monitor
            final_x = mx + (mode->width-sx)/2;
            final_y = my + (mode->height-sy)/2;

            best_area = area;
        }

    }

    // We found something
    if( best_area )
        glfwSetWindowPos( window , final_x , final_y );

    // Something is wrong - current window has NOT any intersection with any monitors. Move it to the default one.
    else
    {
        GLFWmonitor * primary = glfwGetPrimaryMonitor( );
        if( primary )
        {
            const GLFWvidmode * desktop = glfwGetVideoMode( primary );

            if( desktop )
                glfwSetWindowPos( window , (desktop->width-sx)/2 , (desktop->height-sy)/2 );
            else
                return false;
        }
        else
            return false;
    }

    return true;
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouseCallback(GLFWwindow* window, double x, double y){
    if(karint::input::mouseCallback)
        karint::input::mouseCallback(x, y);
}

karint::Window::Window(const std::string &title, int width, int height){
    window = glfwCreateWindow(width,height,title.c_str(), nullptr, nullptr);
    if(window == nullptr) {
        glfwTerminate();
        throw karint::KarintException("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        throw karint::KarintException("Failed to initialize GLAD");
    }

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetCursorPosCallback(window, mouseCallback);

    glViewport(0, 0, width, height);
    glfwSetWindowCenter(window);
}

void karint::Window::getSize(int *width, int *height)
{
    glfwGetWindowSize(window, width, height);
}

bool karint::Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void karint::Window::update() {
    glfwMakeContextCurrent(window);
    glfwSwapBuffers(window);
}

void karint::Window::dispose() {
    glfwDestroyWindow(window);
}

void karint::Window::close() {
    glfwSetWindowShouldClose(window, true);
}

void karint::Window::makeCurrent()
{
    currentWindow = this;
}

karint::Window *karint::Window::getCurrent()
{
    return currentWindow;
}

bool karint::Window::isPressed(int key) {
    int state = glfwGetKey(window, key);
    return state == GLFW_REPEAT || state == GLFW_PRESS;
}

float karint::Window::getDeltaTime() const {
    return deltaTime;
}

void karint::Window::hideCursor(bool mode) {
    glfwSetInputMode(window, GLFW_CURSOR, mode ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}




