#pragma once
#include <exception>
#include <string>
#include <iostream>
#include "logger.h"

namespace karint {
    class KarintException : public std::exception {
    private:
        std::string message;
    public:
        explicit KarintException(const std::string &message){
            this->message = message;
            logger::error("runtime exception", message.c_str());
        }
        const char * what() const noexcept override {
            return message.c_str();
        }
    };
}
