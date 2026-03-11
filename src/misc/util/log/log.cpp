#include <Arduino.h>
#include "log.h"

String getTimestamp()
{
    unsigned long seconds = millis() / 1000;

    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;

    char buffer[12];
    sprintf(buffer, "[%02d:%02d:%02d]", h, m, s);

    return String(buffer); // [00:01:32]
}

void log(const char* msg, bool logTimeStamp)
{
    if(logTimeStamp) {
        Serial.print(getTimestamp());
        Serial.print(" ");
    }

    Serial.println(msg);
}



