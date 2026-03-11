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

void testLogColors()
{
    Serial.println("\n===== LOG COLOR TEST =====");

    Serial.println("\x1B[31m[ERROR]   Hello from RED message\x1B[0m");
    Serial.println("\x1B[32m[SUCCESS] Hello from GREEN message\x1B[0m");
    Serial.println("\x1B[33m[WARN]    Hello from YELLOW message\x1B[0m");
    Serial.println("\x1B[34m[INFO]    Hello from BLUE message\x1B[0m");
    Serial.println("\x1B[35m[DEBUG]   Hello from MAGENTA message\x1B[0m");
    Serial.println("\x1B[36m[TRACE]   Hello from CYAN message\x1B[0m");
    Serial.println("\x1B[37m[NOTE]    Hello from WHITE message\x1B[0m");

    Serial.println("\x1B[91m[ERROR]   Hello from BRIGHT RED message\x1B[0m");
    Serial.println("\x1B[92m[SUCCESS] Hello from BRIGHT GREEN message\x1B[0m");
    Serial.println("\x1B[93m[WARN]    Hello from BRIGHT YELLOW message\x1B[0m");
    Serial.println("\x1B[94m[INFO]    Hello from BRIGHT BLUE message\x1B[0m");

    Serial.println("===== END COLOR TEST =====\n");
}



