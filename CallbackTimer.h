#ifndef CALLBACKTIMER_H
#define CALLBACKTIMER_H

#include <Arduino.h>

class CallbackTimer {
  public:
    using TimerExpiredCallback = void (*)();
    
    CallbackTimer(unsigned long timer_ms, TimerExpiredCallback callback = nullptr);
    
    void configure(unsigned long timer_ms, TimerExpiredCallback callback = nullptr);
    
    void setTimerMS(unsigned long timer_ms);
    unsigned long getTimerMS();
    
    void setTimerExpiredCallback(TimerExpiredCallback callback = nullptr);
    TimerExpiredCallback getTimerExpiredCallback();
    
    void setDisabled(bool disable = true);
    void setEnabled(bool enable = true);
    bool getDisabled();
    bool getEnabled();
    
    void restartTimer();
    
    void skipTimer();
    
    unsigned long getLastRunTimestamp();
    
    unsigned long getTimeElapsed();
    
    unsigned long getTimeRemaining();
    
    bool checkExpired();
    
  private:
    unsigned long timer_ms = 0;
    TimerExpiredCallback callback = nullptr;
    bool disabled = false;
    unsigned long last_run_timestamp = 0;
};

#endif