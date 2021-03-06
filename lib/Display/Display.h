#ifndef __Display_H
#define __Display_H

#include "../../src/settings.cpp"
#include <SPI.h>
#include <TFT_eSPI.h>
#include <GfxUi.h>
#include <MeteoData.h>
#include <WiFi.h>
#include <EEPROM.h>
#include <JpegUtils.h>

struct temperatureParts
{
  int temperature;
  long decimal;
};

class Display
{
public:
  static void initialize();
  static void welcomeScreen(bool);
  static void printWifiStatusAndPrepareTemplate();
  static void printLocalMeteoData();
  static void printSensorsMeteoData();
  static void printProgressBar(int);
  static void prinTargetTemperature(int);
  static void printHeatingStatus(int, String);
  static void checkDisplayClicked();

private:
  static void testMissingFiles();
  static void displayMeteoData(float temperature, int humidity, int offsetY);
  static void printTempleate(int offsetY, String description);
  static void prepareTemplate();
  static void setTargetTemperatureToEEPROMAndDisplay(bool);
  static void setHeatingEnableToEEPROMAndDisplay();
  static temperatureParts getTEmperatureParts(float temperature);
};

#endif
