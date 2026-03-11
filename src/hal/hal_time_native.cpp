#include <chrono>
#include "hal_time.h"

unsigned long hal_time_ms()
{
    using namespace std::chrono;

    static auto start = steady_clock::now();
    auto now = steady_clock::now();

    return duration_cast<milliseconds>(now - start).count();
}