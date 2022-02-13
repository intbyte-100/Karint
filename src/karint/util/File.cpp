#include <fstream>
#include <sstream>
#include "File.h"
#include "FileNotFoundException.h"

std::string karint::File::getPath() {
    return path;
}

karint::File karint::File::load(const std::string& path) {
    File file(path);
    if(file.exist()) return file;

    std::string message("file ");
    message.append(path).append(" is not found");

    throw FileNotFoundException(message);
}

bool karint::File::exist() {
    if (FILE *file = fopen(path.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

karint::File::File(const std::string& path) {
    this->path = path;
}

void karint::File::reopen(const std::string& pathToFile) {
    this->path = pathToFile;
}

std::string karint::File::read() {
    std::ifstream file;
    std::stringstream string;

    file.open(path);
    string << file.rdbuf();
    file.close();

    return string.str();
}
