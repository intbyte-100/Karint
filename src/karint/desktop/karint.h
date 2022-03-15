#include <GLFW/glfw3.h>
#ifndef karintENGINE_karint_H
#define karintENGINE_karint_H

namespace karint {
    void init();
    void update();
    void terminate();
    void systemDialog(const char* title, const char* text);
}

#endif
