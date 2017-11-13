// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <VirtualWire.h>

#define RXPIN 11
#define LEDPIN 8

char *controller;

void setup()
{
  Serial.begin(9600);

  // Init TX module
  vw_set_ptt_inverted(true); //
  vw_set_rx_pin(RXPIN);
  vw_setup(500); // speed of data transfer Kbps
  pinMode(LEDPIN, OUTPUT);
  vw_rx_start();
}

void loop()
{
  // digitalWrite(LEDPIN, LOW);
  char msg[4];

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  memset(msg, 0, 4);
  vw_wait_rx();
  vw_get_message(buf, &buflen);
  Serial.println("Received msg");
  for (int i = 0; i < buflen; i++)
    msg[i] = char(buf[i]);
  msg[buflen] = '\0';
  Serial.println(msg);
  // Serial.println("Test");
  // digitalWrite(LEDPIN, HIGH);
}