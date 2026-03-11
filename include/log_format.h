#pragma once
#include <string>

struct ColoredText
{
    const char* color;
    std::string text;
};

inline ColoredText magenta(const std::string& s)
{
    return {"\x1B[35m", s};
}

inline ColoredText blue(const std::string& s)
{
    return {"\x1B[34m", s};
}

inline ColoredText red(const std::string& s)
{
    return {"\x1B[31m", s};
}

inline ColoredText green(const std::string& s)
{
    return {"\x1B[32m", s};
}

inline std::string apply_color(const ColoredText& c)
{
    return std::string(c.color) + c.text + "\x1B[0m";
}