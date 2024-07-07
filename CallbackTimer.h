#ifndef CALLBACKTIMER_H
#define CALLBACKTIMER_H

#include <Arduino.h>

class CallbackTimer {
  public:
    using TimerExpiredCallback = std::function<void()>;

    CallbackTimer(unsigned long timer_duration, TimerExpiredCallback callback = nullptr);

    void configure(unsigned long timer_duration, TimerExpiredCallback callback = nullptr);
    
    void setTimerDuration(unsigned long timer_duration);
    unsigned long getTimerDuration();
    
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
    
    virtual unsigned long getCurrentTime() const;
    
  private:
    unsigned long timer_duration = 0;
    TimerExpiredCallback callback = nullptr;
    bool disabled = false;
    unsigned long last_run_timestamp = 0;
};

class MicrosCallbackTimer : public CallbackTimer {
  public:
    unsigned long getCurrentTime() const override;
};

#endif // CALLBACKTIMER_H
