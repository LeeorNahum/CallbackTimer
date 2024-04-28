#include "CallbackTimer.h"

CallbackTimer::CallbackTimer(unsigned long timer_duration, TimerExpiredCallback callback) {
  this->configure(timer_duration, callback);
}

void CallbackTimer::configure(unsigned long timer_duration, TimerExpiredCallback callback) {
  this->setTimerDuration(timer_duration);
  this->setTimerExpiredCallback(callback);
}

void CallbackTimer::setTimerDuration(unsigned long timer_duration) {
  this->timer_duration = timer_duration;
  this->restartTimer();
}

unsigned long CallbackTimer::getTimerDuration() {
  return this->timer_duration;
}

void CallbackTimer::setTimerExpiredCallback(TimerExpiredCallback callback) {
  this->callback = callback;
}

CallbackTimer::TimerExpiredCallback CallbackTimer::getTimerExpiredCallback() {
  return this->callback;
}

void CallbackTimer::setDisabled(bool disable) {
  this->disabled = disable;
  if (this->getEnabled()) {
    this->restartTimer();
  }
}

void CallbackTimer::setEnabled(bool enable) {
  this->disabled = !enable;
  if (this->getEnabled()) {
    this->restartTimer();
  }
}

bool CallbackTimer::getDisabled() {
  return this->disabled;
}

bool CallbackTimer::getEnabled() {
  return !this->disabled;
}

void CallbackTimer::restartTimer() {
  this->last_run_timestamp = this->getCurrentTime();
}

void CallbackTimer::skipTimer() {
  this->last_run_timestamp = this->getCurrentTime() + this->getTimerDuration(); // TODO fixed?
}

unsigned long CallbackTimer::getLastRunTimestamp() {
  return this->last_run_timestamp;
}

unsigned long CallbackTimer::getTimeElapsed() {
  return this->getCurrentTime() - this->getLastRunTimestamp();
}

unsigned long CallbackTimer::getTimeRemaining() {
  unsigned long elapsed = this->getTimeElapsed();
  if (this->getTimerDuration() > elapsed) {
    return this->getTimerDuration() - elapsed;
  }
  return 0;
}

bool CallbackTimer::checkExpired() {
  if (this->getDisabled()) {
    return false;
  }
  
  if (this->getTimeElapsed() > this->getTimerDuration()) {
    this->restartTimer();
    if (this->getTimerExpiredCallback() != nullptr) {
      this->getTimerExpiredCallback()();
    }
    return true;
  }
  return false;
}

unsigned long CallbackTimer::getCurrentTime() const {
  return millis();
}

unsigned long MicrosCallbackTimer::getCurrentTime() const {
  return micros();
}