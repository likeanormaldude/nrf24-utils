#include <Arduino.h>
#include "hal_serial.h"

void hal_serial_print(const char* msg)
{
    Serial.print(msg);
}

void hal_serial_println(const char* msg)
{
    Serial.println(msg);
}