#include <CallbackTimer.h>

const int LED_PIN = 13;

// Create a CallbackTimer object with a 500ms timer
CallbackTimer blink_delay(500);

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Check if the CallbackTimer object has expired
  if (blink_delay.checkExpired()) {
    // Toggle the LED state
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
