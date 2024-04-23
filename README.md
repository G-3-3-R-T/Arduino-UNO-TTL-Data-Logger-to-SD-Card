# Arduino-UNO-TTL-Data-Logger-to-SD-Card

This is a TTL Data logger that writes the data to an SD-Card.
The used hardware is a Arduino UNO and a micro SD-Card adapter (OPEN-SMART microSD Card Adapter).

The wiring between the SD-Card adapter and the Arduino UNO is as follow:

SD Card Shield  -  Arduino Uno
VCC	       -          5V

GND	       -          GND

MISO	     -      Digital Pin 12

MOSI	     -      Digital Pin 11

SCK	       -      Digital Pin 13

CS	       -      Digital Pin 10


It will continious write data to the SD card all the data it receives on the pin-0 (RX Pin) af the Arduino UNO.
The RX input is set to receive data rate of 115200 baud. (you can easely change this buad rate in the code acording your needs)

It can also be used to log serial RS232 data but you need ta add a MAX232 chip to convert the signal.
