#include "CallbackTimer.h"

CallbackTimer::CallbackTimer(unsigned long timer_ms, TimerExpiredCallback callback) {
  this->configure(timer_ms, callback);
}

void CallbackTimer::configure(unsigned long timer_ms, TimerExpiredCallback callback) {
  this->setTimerMS(timer_ms);
  this->setTimerExpiredCallback(callback);
}

void CallbackTimer::setTimerMS(unsigned long timer_ms) {
  this->timer_ms = timer_ms;
  this->restartTimer();
}

unsigned long CallbackTimer::getTimerMS() {
  return this->timer_ms;
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
  this->last_run_timestamp = millis();
}

void CallbackTimer::skipTimer() {
  this->last_run_timestamp = this->getTimerMS();
}

unsigned long CallbackTimer::getLastRunTimestamp() {
  return this->last_run_timestamp;
}

unsigned long CallbackTimer::getTimeElapsed() {
  return millis() - this->getLastRunTimestamp();
}

unsigned long CallbackTimer::getTimeRemaining() {
  unsigned long elapsed = this->getTimeElapsed();
  if (this->getTimerMS() > elapsed) {
    return this->getTimerMS() - elapsed;
  }
  return 0;
}

bool CallbackTimer::checkExpired() {
  if (this->getDisabled()) {
    return false;
  }
  
  if (this->getTimeElapsed() > this->getTimerMS()) {
    this->restartTimer();
    if (this->callback != nullptr) {
      this->callback();
    }
    return true;
  }
  return false;
}