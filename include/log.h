#pragma once
#include <string>
#include "log_format.h"

class Log
{
public:
    void info(const char* msg);

    void replace_placeholder(std::string& msg, const std::string& value)
    {
        auto pos = msg.find("%t");
        if (pos != std::string::npos)
            msg.replace(pos, 2, value);
    }

    void format_impl(std::string& msg) {}

    template<typename T, typename... Args>
    void format_impl(std::string& msg, const T& first, const Args&... rest)
    {
        replace_placeholder(msg, apply_color(first));
        format_impl(msg, rest...);
    }

    template<typename... Args>
    void info(const char* fmt, const Args&... args)
    {
        std::string msg(fmt);
        format_impl(msg, args...);
        info(msg.c_str());
    }

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