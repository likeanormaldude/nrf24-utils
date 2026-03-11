#pragma once
#include <string>

class Log
{
public:
    void info(const char* msg);
    void success(const char* msg);
    void warn(const char* msg);
    void error(const char* msg);
    void debug(const char* msg);
    void testLogColors();
    std::string timestamp();

private:
    void print(const char* level, const char* color, const char* msg);
};

extern Log logger;