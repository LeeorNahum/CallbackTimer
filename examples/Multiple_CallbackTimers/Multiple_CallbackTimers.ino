#include <CallbackTimer.h>

// Create three CallbackTimer objects with different delay times
CallbackTimer delay1(2000);
CallbackTimer delay2(3000);
CallbackTimer delay3(4000, [] {
  Serial.println("Delay 3 expired!");
});

void setup() {
  // Initialize the serial port for debugging
  Serial.begin(9600);
}

void loop() {
  // Check if the first CallbackTimer object has expired
  if (delay1.checkExpired()) {
    Serial.println("Delay 1 expired!");
  }
  
  // Check if the second CallbackTimer object has expired
  if (delay2.checkExpired()) {
    Serial.println("Delay 2 expired!");
  }
  
  // Check if the third CallbackTimer object has expired
  delay3.checkExpired();
}
