#include <ArduinoBLE.h>

BLEService loggingService("19B10000-E8F2-537E-4F6C-D104768A1214");
BLECharacteristic logCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLENotify, 20);

void setupBLE() {
  if (!BLE.begin()) {
    Serial.println("BLE failed to start");
    return;
  }

  BLE.setLocalName("ArtemisLogger");
  BLE.setAdvertisedService(loggingService);
  loggingService.addCharacteristic(logCharacteristic);
  BLE.addService(loggingService);
  BLE.advertise();

  Serial.println("BLE Logger active");
}

void sendLogToBLE(const char* logData) {
  if (BLE.connected()) {
    logCharacteristic.writeValue(logData);
  }
}

// Call this function in your main setup()
void AOAsetup() {
  setupBLE();
}

// Call this function in your main loop()
void AOAloop() {
  BLE.poll();
}