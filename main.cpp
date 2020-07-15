#include <Arduino.h>
#include <TinyPICO.h>
#include <BLEAdvertisedDevice.h>
#include <BLEDevice.h>
#include <BLEScan.h>

TinyPICO tp = TinyPICO();


const int CUTOFF = -60;

void setup() {

  BLEDevice::init("Andrew");
}

void loop() {
  BLEScan *scan = BLEDevice::getScan();
  scan->setActiveScan(true);
  BLEScanResults results = scan->start(1);
  int best = CUTOFF;
  for (int i = 0; i < results.getCount(); i++) {
    BLEAdvertisedDevice device = results.getDevice(i);
    int rssi = device.getRSSI();
    if (rssi > best) {
      best = rssi;
    }
  
  }
  if (best > CUTOFF) tp.DotStar_SetPixelColor( 255, 128, 0 );
  if (best == CUTOFF) tp.DotStar_SetPixelColor( 0, 0, 0 );
}

 
