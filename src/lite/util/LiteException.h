#include <exception>
#include <string>
#include <iostream>

namespace lite {
    class LiteException : std::exception {
    private:
        const char * message;
    public:
        explicit LiteException(const std::string &message){
            this->message = message.c_str();
            std::cout << "ERROR: " << message << std::endl;
        }
        const char * what() const noexcept override {
            return message;
        }
    };
}
