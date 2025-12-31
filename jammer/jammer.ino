/*
 * Project: 2.4GHz Channel Sweeper using nRF24L01
 * Hardware: Arduino Uno + nRF24L01
 * 
 * Author: SecureTechware
 * Website: https://securetechware.com
 * 
 * Description:
 * This sketch initializes the nRF24L01 radio module and transmits a 
 * continuous carrier signal while cycling through all 2.4GHz channels.
 * It also covers BLE advertisement channels for comprehensive analysis.
 * 
 * Use Case:
 * - Controlled RF environment testing
 * - Interference or channel activity verification
 * - RF laboratory experiments
 * 
 * Dependencies:
 *   - RF24 Library (by TMRh20): https://github.com/tmrh20/RF24/
 */

#include <RF24.h>
RF24 radio(9, 10);

#define BUTTON 3
#define LED 4

byte startChannel = 45;


void sweepChannelsRecursive(int ch) {
  if (ch >= 79) return;              // Stop once all 79 channels are covered
  radio.setChannel(ch);              // Set current channel
  sweepChannelsRecursive(ch + 1);    // Recursively move to next channel
}

void sweepBleRecursive(const byte *arr, int idx, int len) {
  if (idx >= len) return;            // Stop once all BLE channels are done
  radio.setChannel(arr[idx]);        // Set BLE channel
  sweepBleRecursive(arr, idx + 1, len);  // Move to next BLE channel
}


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  if(!digitalRead(BUTTON)){
    //digitalWrite(LED, HIGH);

    if (radio.begin()) {
      delay(500);

      // Radio configuration
      radio.setAutoAck(false);             // Disable auto acknowledgment
      radio.stopListening();               // Switch to transmit mode
      radio.setRetries(0, 0);              // Disable retransmission
      radio.setPayloadSize(5);             // Minimal payload size
      radio.setAddressWidth(3);            // 3-byte address width
      radio.setPALevel(RF24_PA_MAX, true); // Set max power with high current
      radio.setDataRate(RF24_2MBPS);       // Highest data rate
      radio.setCRCLength(RF24_CRC_DISABLED); // Disable CRC for raw output
      radio.startConstCarrier(RF24_PA_MAX, startChannel);
    } else {
      while(true);
    }
  }else{
    while(true);
  }
}


void loop() {
  // Sweep all standard 2.4GHz ISM channels
  sweepChannelsRecursive(0);

  byte bleChannels[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36,
    37, 38, 39
  };

  // Sweep BLE channels
  sweepBleRecursive(bleChannels, 0, 3);
}