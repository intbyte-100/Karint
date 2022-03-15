#include <iostream>
#include "logger.h"
#include "karint/desktop/karint.h"
#include "karint/desktop/Window.h"


bool karint::logger::debugMode = false;

inline void log(const char *type, const char *label, const char *message) {
    std::cout << '[' << type << ": " << label << ']' << " " << message << std::endl;
}

void karint::logger::debug(const char *label, const char *message) {
    if (debugMode) log("DEBUG", label, message);
}

void karint::logger::error(const char *label, const char *message) {
    log("ERROR", label, message);
}

void karint::logger::fatalError(const char *label, const char *message) {
    #if defined(__unix__) || defined(_WIN32_)
    Window::getCurrent()->hideCursor(false);
    glfwPollEvents();
    #endif
    log("FATAL ERROR", label, message);
    systemDialog(label, message);
}

void karint::logger::info(const char *label, const char *message) {
    log("INFO", label, message);
}
