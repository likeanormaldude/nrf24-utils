#include <Arduino.h>
#include "radio.h"
#include "../log/log.h"

const uint8_t Radio::pipes[2][6] = {"1Node", "2Node"};

Radio::Radio(uint8_t cePin, uint8_t csnPin, bool radioNumber) // Constructor
    : radio(cePin, csnPin), radioNumber(radioNumber) // assignment of private members
{
}

void Radio::init()
{
    radio.begin();
    radio.setChannel(125);
    radio.setDataRate(RF24_2MBPS);

    if (!radioNumber)
    {
        radio.openWritingPipe(pipes[0]);
        radio.openReadingPipe(1, pipes[1]);
    }
    else
    {
        radio.openWritingPipe(pipes[1]);
        radio.openReadingPipe(1, pipes[0]);
    }

    radio.startListening();
}

void Radio::startReceiver()
{
    log("ESP32 > NRF24L01 Receive text");
    init();
}

bool Radio::isCommunicationOk(bool keepTrying)
{
    bool isConnected = false;

    while (!isConnected)
    {
        isConnected = radio.isChipConnected();

        if (!keepTrying)
            break;
    }

    return isConnected;
}

void Radio::checkConnection(bool printPrettyDetails)
{
    log("======= Checking connection for ESP32 > NRF24L01... =======", false);

    startReceiver();

    if (isCommunicationOk())
        log("[SUCCESS] - Receiver NRF24 \x1B[32mconnected\x1B[0m to SPI!");
    else
        log("[FAIL] - NRF24 \x1B[31mNOT\x1B[0m connected to SPI.");

    if (printPrettyDetails)
        radio.printDetails();

    log("======= Checking connection finished. =======", false);
}

bool Radio::receiveData(char *buffer, uint8_t size)
{
    if (radio.available())
    {
        radio.read(buffer, size);
        return true;
    }

    return false;
}