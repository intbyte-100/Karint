#pragma once

#ifdef KARINT_DEBUG
#include <iostream>
#define karint_debug_log(label, message) std::cout << "[ENGINE_DEBUG: " << label << "] " << message << std::endl
#else
#define karint_debug_log(label, message)
#endif
namespace karint {
    namespace logger {
        extern bool debugMode;
        void debug(const char *label, const char *message);
        void info(const char *label, const char *message);
        void error(const char *label, const char *message);
        void fatalError(const char *label, const char *message);
    }
};



