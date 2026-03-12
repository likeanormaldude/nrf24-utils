#pragma once

#include <string>
#include "log_format.h"

class Log
{
public:
    void info(const char* msg);
    void success(const char* msg);
    void warn(const char* msg);
    void error(const char* msg);
    void debug(const char* msg);
    void printRaw(const char* msg);

    template<typename... Args>
    void info(const char* fmt, const Args&... args)
    {
        info(format_message(fmt, args...).c_str());
    }

    template<typename... Args>
    void success(const char* fmt, const Args&... args)
    {
        success(format_message(fmt, args...).c_str());
    }

    template<typename... Args>
    void warn(const char* fmt, const Args&... args)
    {
        warn(format_message(fmt, args...).c_str());
    }

    template<typename... Args>
    void error(const char* fmt, const Args&... args)
    {
        error(format_message(fmt, args...).c_str());
    }

    template<typename... Args>
    void debug(const char* fmt, const Args&... args)
    {
        debug(format_message(fmt, args...).c_str());
    }

    template<typename... Args>
    void printRaw(const char* fmt, const Args&... args)
    {
        printRaw(format_message(fmt, args...).c_str());
    }

    void testLogColors();
    std::string timestamp();

private:
    void print(const char* level, const char* color, const char* msg);

    static void replace_placeholder(std::string& msg, const std::string& value)
    {
        auto pos = msg.find("%t");
        if (pos != std::string::npos)
            msg.replace(pos, 2, value);
    }

    static void format_impl(std::string&) {}

    template<typename T, typename... Args>
    static void format_impl(std::string& msg, const T& first, const Args&... rest)
    {
        replace_placeholder(msg, apply_color(first));
        format_impl(msg, rest...);
    }

    template<typename... Args>
    static std::string format_message(const char* fmt, const Args&... args)
    {
        std::string msg(fmt);
        format_impl(msg, args...);
        return msg;
    }
};

extern Log logger;