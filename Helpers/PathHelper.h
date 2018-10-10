//
// Created by Antoine Botteler on 08/10/2018.
//

#ifndef INVENTORYSYSTEM_PATHHELPER_H
#define INVENTORYSYSTEM_PATHHELPER_H

#include <string>
#include <vector>
#include <exception>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <sstream>
  #include <unistd.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>

#endif

std::string getCurrentPath()
{
    unsigned int bufferSize = 512;
    std::vector<char> buffer(bufferSize + 1);
    std::string s;
#if defined(__APPLE__)
    if(_NSGetExecutablePath(&buffer[0], &bufferSize))
    {
        buffer.resize(bufferSize);
        _NSGetExecutablePath(&buffer[0], &bufferSize);
    }

    s = &buffer[0];
    size_t lastOf = s.find_last_of('/');
    s = s.substr(0,lastOf+1);
#elif
    return ""; // PLEASE IMPLEMENT WINDOWS AND LINUX SPECIFIC FILE LOADERS!!!
#endif

    return s;
}

std::string getPath(const std::string *path)
{
    std::string string;
    if(path->length() == 0) return getCurrentPath();
    if(path->at(0) == '\\' || path->at(0) == '/') {
        string.append(*path);
        return string;
    }

    string.append(getCurrentPath());
    string.append("\\");
    string.append(*path);
    return string;
}


#endif //INVENTORYSYSTEM_PATHHELPER_H
