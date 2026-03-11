#include <Arduino.h>
#include <RF24.h>

#include "radio.h"
#include "log.h"

static const uint8_t pipes[2][6] = {"1Node", "2Node"};

static RF24 radio(4, 5);   // CE / CSN example

static bool radioNumber;

Radio::Radio(uint8_t cePin, uint8_t csnPin, bool number)
{
    radio = RF24(cePin, csnPin);
    radioNumber = number;
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
    logger.info("ESP32 > NRF24L01 Receive text");
    init();
}

bool Radio::isCommunicationOk(bool keepTrying)
{
    bool connected = false;

    while (!connected)
    {
        connected = radio.isChipConnected();

        if (!keepTrying)
            break;
    }

    return connected;
}

void Radio::checkConnection(bool printPrettyDetails)
{
    logger.info("======= Checking connection for ESP32 > NRF24L01... =======");

    startReceiver();

    if (isCommunicationOk())
        logger.info("Receiver NRF24 connected to SPI!");
    else
        logger.error("NRF24 NOT connected to SPI.");

    if (printPrettyDetails)
        radio.printDetails();

    logger.info("======= Checking connection finished. =======");
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