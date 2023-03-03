#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("YourDeviceName");
  Serial.println("Bluetooth started");
}

void loop() {
  if(SerialBT.available()){
    String request = SerialBT.readStringUntil('\r');
    Serial.println(request);
  }
  delay(10);
}
