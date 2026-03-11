#include <Arduino.h>
#include "hal_time.h"

unsigned long hal_time_ms()
{
    return millis();
}