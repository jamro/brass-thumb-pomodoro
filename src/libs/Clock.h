#ifndef Clock_h
#define Clock_h

#include "Arduino.h"
#include "ModeSwitch.h"
#include "Timer.h"

/**
 * Clock class to manage timing for work and break periods.
 * Provides functionality to start, stop, and restart the clock, and track progress.
 */
class Clock {
  public:
    /**
     * Constructor to initialize Clock object with specified work and break times.
     * @param workTime - The duration of work mode in milliseconds.
     * @param breakTime - The duration of break mode in milliseconds.
     */
    Clock(unsigned long workTime, unsigned long breakTime);

    /**
     * Get the current mode of the clock.
     * @return The current mode.
     */
    int getMode();

    /**
     * Get the progress of the current mode as a float between 0.0 and 1.0.
     * @return The progress of the current mode.
     */
    float getProgress();

    /**
     * Start the clock in the specified mode.
     * @param mode - The mode to start the clock in.
     */
    void start(int mode);

    /**
     * Stop the clock and set it to IDLE_MODE.
     */
    void stop();

    /**
     * Restart the clock in the specified mode.
     * @param mode - The mode to restart the clock in.
     */
    void restart(int mode);

    /**
     * Get the elapsed time from the timer.
     * @return The elapsed time in milliseconds.
     */
    unsigned long getTime();

    /**
     * Check if the clock is running.
     * @return True if the clock is running, false otherwise.
     */
    bool isRunning();

    /**
     * Check if the clock is paused.
     * @return True if the clock is in IDLE_MODE, false otherwise.
     */
    bool isPaused();

    /**
     * Check if the clock has completed its current mode.
     * @return True if the clock is complete, false otherwise.
     */
    bool isComplete();

  private:
    void _setMode(int mode);
    unsigned long _workTime;
    unsigned long _breakTime;
    int _mode;
    int _prevMode;
    Timer _timer;
};

#endif
