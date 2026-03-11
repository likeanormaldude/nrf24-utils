#ifdef ARDUINO

#include <Arduino.h>
#include "log.h"

void setup() {}

void loop() {
    logger.testLogColors();
}

#else

#include "log.h"

int main() {
    logger.testLogColors();
    return 0;
}

#endif