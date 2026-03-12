#include "log.h"
#include "hal_serial.h"
#include "hal_time.h"

#include <cstdio>

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"

Log logger;

void Log::print(const char* level, const char* color, const char* msg)
{
    hal_serial_print(timestamp().c_str());
    hal_serial_print(" ");

    hal_serial_print(color);
    hal_serial_print("[");
    hal_serial_print(level);
    hal_serial_print("]");
    hal_serial_print(RESET);

    hal_serial_print(" ");
    hal_serial_println(msg);
}

void Log::printRaw(const char* msg)
{
    hal_serial_print(timestamp().c_str());
    hal_serial_print(" ");
    hal_serial_println(msg);
}

void Log::info(const char* msg)
{
    print("INFO", BLUE, msg);
}

void Log::success(const char* msg)
{
    print("SUCCESS", GREEN, msg);
}

void Log::warn(const char* msg)
{
    print("WARN", YELLOW, msg);
}

void Log::error(const char* msg)
{
    print("ERROR", RED, msg);
}

void Log::debug(const char* msg)
{
    print("DEBUG", MAGENTA, msg);
}

void Log::testLogColors()
{
    info("Booting system");
    success("NRF24 connected");
    warn("Signal strength low");
    error("Packet lost");
    debug("Payload size: 32 bytes");

    info("Colored %t %t", magenta("hello"), blue("world"));
    printRaw("Raw colored %t %t", magenta("hello"), blue("world"));
}

std::string Log::timestamp()
{
    unsigned long seconds = hal_time_ms() / 1000;

    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;

    char buffer[16];
    sprintf(buffer, "[%02d:%02d:%02d]", h, m, s);

    return std::string(buffer);
}