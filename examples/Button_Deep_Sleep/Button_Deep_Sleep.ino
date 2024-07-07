#include <CallbackTimer.h>

const int BUTTON_PIN = 2;

// Create a CallbackTimer object with a 60 second timer
CallbackTimer sleep_timer(60000);

void setup() {
  // Initialize the button pin as an input pullup
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Set the sleep callback to run esp_deep_sleep_start()
  sleep_timer.setTimerExpiredCallback([] {
    esp_deep_sleep_start();
  });
}

void loop() {
  // Do some work
  // ...

  // Restart the sleep timer if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    sleep_timer.restartTimer();
  }

  // Check if it's time to go to sleep
  sleep_timer.checkExpired();
}