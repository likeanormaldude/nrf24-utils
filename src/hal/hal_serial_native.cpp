#include <iostream>
#include "hal_serial.h"

void hal_serial_print(const char* msg)
{
    std::cout << msg;
}

void hal_serial_println(const char* msg)
{
    std::cout << msg << std::endl;
}