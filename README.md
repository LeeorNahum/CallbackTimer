# CallbackTimer

An Arduino library for creating timers with callback functions when the timer expires.

## Description

The CallbackTimer library allows you to create repeating timers and add an optional callback function that will be executed when the time has expired. The library also provides methods for controlling the timer such as restarting, skipping, enabling/disabling, and checking the timer's expiration status.

## Features

- Configure the timer with a specified time in milliseconds (or microseconds).
- Provide an optional callback function to be executed when the timer expires.
- Restart, skip, and enable/disable the timer.
- Check the time remaining, time elapsed, and if the timer has expired.

## Usage

Here is an example of how to use the CallbackTimer library:

``` C++
#include <CallbackTimer.h>

void timerExpired() {
  // Your code here to be executed when the timer expires
}

CallbackTimer timer(10000, timerExpired); // timer set for 10 seconds

void setup() {
  timer.setEnabled();
}

void loop() {
  timer.checkExpired();
}
```
