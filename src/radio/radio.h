#ifndef RADIO_H
#define RADIO_H

#include <Arduino.h>
#include <RF24.h>

class Radio
{
private:
    RF24 radio;
    bool radioNumber;

    static const uint8_t pipes[2][6];

public:
    Radio(uint8_t cePin, uint8_t csnPin, bool radioNumber);

    void init();
    void startReceiver();
    bool isCommunicationOk(bool keepTrying = false);
    void checkConnection(bool printPrettyDetails = false);
    bool receiveData(char *buffer, uint8_t size);
};

#endif