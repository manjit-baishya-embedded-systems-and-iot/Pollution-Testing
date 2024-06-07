#include <HardwareSerial.h>

// Use UART2 (or Serial2) for communication
HardwareSerial Serial2(2);

void setup() {
  // Start the default Serial0 (USB) at 115200 baud for debugging
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for the serial port to be ready
  }

  // Start Serial2 at 9600 baud (change baud rate as needed)
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // GPIO16 as RX, GPIO17 as TX
  Serial.println("ESP32 UART is ready.");
}

void loop() {
  if (Serial2.available()) {
    // Read the incoming byte from Serial2 (UART)
    char incomingByte = Serial2.read();
    // Print the incoming byte to the default Serial0 (USB)
    Serial.print(incomingByte);
  }
}
