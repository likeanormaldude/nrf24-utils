#include "radio.h"

// -----------------------------------------------------------------------------
// Address pipes used by the NRF24L01 radio for communication.
// Each pipe is a 5-byte address. These must match the transmitter configuration.
// -----------------------------------------------------------------------------
const uint8_t pipes[][6] = {"1Node", "2Node"};

// -----------------------------------------------------------------------------
// initRadio()
// Initializes the NRF24L01 radio with basic configuration settings.
//
// Parameters:
//   radio        -> reference to the RF24 radio object
//   radioNumber  -> determines which address pipe this device will use
//
// Why pass by reference (&)?
//   Passing by reference avoids copying the RF24 object and allows us to
//   configure the same radio instance created in the main program.
// -----------------------------------------------------------------------------
void initRadio(RF24 &radio, bool radioNumber)
{
radio.begin();                 // Initialize the RF24 module and SPI communication

radio.setChannel(125);         // Set RF communication channel (0–125 available)
                               // Both transmitter and receiver must use the same channel

radio.setDataRate(RF24_2MBPS); // Set the data transmission rate
                               // Options: RF24_250KBPS, RF24_1MBPS, RF24_2MBPS

// -------------------------------------------------------------------------
// Configure communication pipes depending on which node this device is.
// This allows two devices to communicate in both directions.
// -------------------------------------------------------------------------
if (!radioNumber)
{
    // Device is Node 0
    radio.openWritingPipe(pipes[0]);    // Address used when sending data
    radio.openReadingPipe(1, pipes[1]); // Address used when receiving data
}
else
{
    // Device is Node 1
    radio.openWritingPipe(pipes[1]);
    radio.openReadingPipe(1, pipes[0]);
}

radio.startListening(); // Put the radio into RX mode (receiver mode)

}

// -----------------------------------------------------------------------------
// checkConnection()
// Verifies if the NRF24L01 module is properly connected to the SPI bus.
//
// Parameters:
//   radio -> reference to the RF24 radio object
//
// The function prints diagnostic information to the serial monitor.
// -----------------------------------------------------------------------------
void checkConnection(RF24 &radio)
{
    if (radio.isChipConnected()) // Checks if SPI communication works
        Serial.println("Receiver NRF24 connected to SPI");
    else
        Serial.println("NRF24 is NOT connected to SPI");
}

// -----------------------------------------------------------------------------
// receiveData()
// Checks if a packet has arrived and reads it into a buffer.
//
// Parameters:
//   radio  -> reference to RF24 object
//   buffer -> pointer to the array where received data will be stored
//   size   -> size of the expected payload
//
// Returns:
//   true  -> if new data was received
//   false -> if no packet is available
// -----------------------------------------------------------------------------
bool receiveData(RF24 &radio, char *buffer, uint8_t size)
{
// Check if a packet is available in the receive buffer
if (radio.available())
{
// Read incoming data into the provided buffer
radio.read(buffer, size);

    return true;  // Indicate that new data has been received
}

return false;     // No data available

}

// -----------------------------------------------------------------------------
// startReceiver()
// Helper function that performs all setup steps required to start the receiver.
//
// Parameters:
//   radio       -> RF24 radio instance
//   radioNumber -> selects which node configuration to use
//
// This function simplifies the main setup() routine.
// -----------------------------------------------------------------------------
void startReceiver(RF24 &radio, bool radioNumber)
{
    Serial.println("ESP32 > NRF24L01 Receive text");

    initRadio(radio, radioNumber); // Initialize radio configuration
    checkConnection(radio); // Verify SPI connection

    radio.printDetails(); // Print detailed NRF24 configuration
}
