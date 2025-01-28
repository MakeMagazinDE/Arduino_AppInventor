#include "BluetoothSerial.h" 

// init Class:
BluetoothSerial ESPSerial; 

// Die 3 LEDs den ESP32-Pins zuordnen:
int led_pin_1 = 4;                  //G4
int led_pin_2 = 0;                  //G0
int led_pin_3 = 2;                  //G2

int incoming;

void setup() {
  Serial.begin(19200);
  ESPSerial.begin("BT_ESP32_Control"); //Name der Bluetooth-Schnittstelle

  pinMode (led_pin_1, OUTPUT);
  pinMode (led_pin_2, OUTPUT);
  pinMode (led_pin_3, OUTPUT);
}

void loop() {
  
  // -------------------- Bluetoothsignal empfangen ----------------------
  if (ESPSerial.available()) 
  {
    incoming = ESPSerial.read(); //Read what we receive 

    int button = floor(incoming / 10);
    int value = incoming % 10;
    
    switch (button) {
      case 1:  
        Serial.print("Button 1:"); Serial.println(value);
        digitalWrite(led_pin_1, value);
        break;
      case 2:  
        Serial.print("Button 2:"); Serial.println(value);
        digitalWrite(led_pin_2, value);
        break;
      case 3:  
        Serial.print("Button 3:"); Serial.println(value);
        digitalWrite(led_pin_3, value);
        break;
    }
  }
}
