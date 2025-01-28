#include "BluetoothSerial.h" // Bibliothek für Bluetooth

BluetoothSerial SerialBT;

const int ledPin1 = 4;      // Verbinde die erste LED mit GPIO4
const int ledPin2 = 0;      // Verbinde die zweite LED mit GPIO0
const int ledPin2 = 2;      // Verbinde die zweite LED mit GPIO2

void setup() {
  // Bluetooth starten
  Serial.begin(115200);
  SerialBT.begin("ESP32_LED_Control"); // Bluetooth-Name
  Serial.println("Bluetooth gestartet. Warte auf Verbindung...");

  // LED-Pins konfigurieren
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char receivedChar = SerialBT.read();
    Serial.println("Empfangen: " + String(receivedChar));

    // Steuerung der LEDs basierend auf den empfangenen Zeichen
    switch (receivedChar) {
      case '1': // LED 1 einschalten
        digitalWrite(ledPin1, HIGH);
        break;
      case '0': // LED 1 ausschalten
        digitalWrite(ledPin1, LOW);
        break;
      case '3': // LED 2 einschalten
        digitalWrite(ledPin2, HIGH);
        break;
      case '2': // LED 2 ausschalten
        digitalWrite(ledPin2, LOW);
        break;
      case '5': // LED 3 einschalten
        digitalWrite(ledPin3, HIGH);
        break;
      case '4': // LED 3 ausschalten
        digitalWrite(ledPin3, LOW);
        break;
      default:
        Serial.println("Unbekannter Befehl");
    }
  }
}
