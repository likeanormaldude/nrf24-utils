// compile without hardware

#include "radio.h"

Radio::Radio(uint8_t cePin, uint8_t csnPin, bool radioNumber)
{
}

void Radio::init() {}

void Radio::startReceiver() {}

bool Radio::isCommunicationOk(bool keepTrying)
{
    return true;
}

void Radio::checkConnection(bool printPrettyDetails) {}

bool Radio::receiveData(char *buffer, uint8_t size)
{
    return false;
}