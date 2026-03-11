#pragma once
#include <stdint.h>

class Radio
{
private:
    bool radioNumber;

public:
    Radio(uint8_t cePin, uint8_t csnPin, bool radioNumber);

    void init();
    void startReceiver();
    bool isCommunicationOk(bool keepTrying = false);
    void checkConnection(bool printPrettyDetails = false);
    bool receiveData(char *buffer, uint8_t size);
};