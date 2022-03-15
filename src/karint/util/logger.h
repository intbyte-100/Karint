#pragma once

namespace karint {
    namespace logger {
        extern bool debugMode;
        void debug(const char *label, const char *message);
        void info(const char *label, const char *message);
        void error(const char *label, const char *message);
        void fatalError(const char *label, const char *message);
    }
};



