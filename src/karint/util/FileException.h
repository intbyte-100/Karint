#include <exception>
#include <iostream>
#include <string>
#include "logger.h"
#include "KarintException.h"

#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

namespace karint {
    class FileException : public KarintException
    {

    public:
        explicit FileException(const std::string &message) : KarintException(message) {}

    };
}

#endif
