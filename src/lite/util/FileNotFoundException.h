#include <exception>
#include <iostream>
#include <string>

#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

namespace lite {
    class FileNotFoundException : std::exception
    {
    private:
        const char *message;

    public:
        explicit FileNotFoundException(const std::string &message)
        {
            this->message = message.c_str();
            std::cout << "ERROR: " << message << std::endl;
        }
        const char *what() const noexcept override { return message; }
    };
}

#endif
