#pragma once

#include <string>

namespace karint {
    class File {
    private:
        std::string path;
    public:
        explicit File(const std::string &path);
        File() = default;
        std::string getPath();
        bool exist();
        void reopen(const std::string& pathToFile);
        std::string read();

        static File load(const std::string &path);
    };
}

