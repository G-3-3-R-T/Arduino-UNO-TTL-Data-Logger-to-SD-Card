#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; // Define the chip select pin for SD card module

const int bufferSize = 128; // Buffer size for incoming data
char buffer[bufferSize];
int bufferIndex = 0;

void setup() {
  Serial.begin(115200);

  pinMode(chipSelect, OUTPUT);  // Set the chip select pin as an output
  digitalWrite(chipSelect, HIGH); // Deselect the SD card initially

  // Initialize SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed. Check your connections.");
    return;
  }
  Serial.println("SD card successfully initialized.");
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    Serial.write(data); // Echo the data back to the serial monitor

    // Store data in buffer
    buffer[bufferIndex++] = data;

    // If buffer is full, write it to SD card
    if (bufferIndex >= bufferSize) {
      writeBufferToSD();
    }
  }
}

void writeBufferToSD() {
  // Write data from buffer to SD card
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    // Write buffer to file
    dataFile.write(buffer, bufferIndex);
    dataFile.close();

    // Reset buffer index
    bufferIndex = 0;
  } else {
    Serial.println("Error opening datalog.txt");
  }
}
