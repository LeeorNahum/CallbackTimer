#include <CallbackTimer.h>

const int LED_PIN = 13;

// Create a CallbackTimer object with a 500ms timer
// and set the timer expired callback to toggle the LED state
CallbackTimer blink_delay(500, [] {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
});

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Check if the CallbackTimer object has expired
  blink_delay.checkExpired();
}
