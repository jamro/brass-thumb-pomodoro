#include "Arduino.h"
#include "Clock.h"
#include "ModeSwitch.h"

/**
 * Constructor to initialize Clock object with specified work and break times.
 * Sets the initial mode to IDLE_MODE and initializes the Timer object.
 * @param workTime - The duration of work mode in milliseconds.
 * @param breakTime - The duration of break mode in milliseconds.
 */
Clock::Clock(unsigned long workTime, unsigned long breakTime) {
  _workTime = workTime;   // Set the work time
  _breakTime = breakTime; // Set the break time
  _mode = IDLE_MODE;      // Initialize mode to idle
  _prevMode = IDLE_MODE;  // Initialize previous mode to idle
  _timer = Timer();       // Initialize the timer
}

/**
 * Get the current mode of the clock.
 * @return The current mode.
 */
int Clock::getMode() {
  return _mode;
}

/**
 * Set a new mode for the clock.
 * Updates the previous mode if the new mode is not IDLE_MODE.
 * @param newMode - The new mode to set.
 */
void Clock::_setMode(int newMode) {
  _mode = newMode;
  if(_mode != IDLE_MODE) {
    _prevMode = _mode; // Update the previous mode if not idle
  }
}

/**
 * Start the clock in the specified mode.
 * @param mode - The mode to start the clock in.
 */
void Clock::start(int mode) {
  _setMode(mode); // Set the mode
  _timer.start(); // Start the timer
}

/**
 * Stop the clock and set it to IDLE_MODE.
 */
void Clock::stop() {
  _setMode(IDLE_MODE); // Set mode to idle
  _timer.stop();       // Stop the timer
}

/**
 * Restart the clock in the specified mode.
 * @param mode - The mode to restart the clock in.
 */
void Clock::restart(int mode) {
  _setMode(mode);     // Set the mode
  _timer.restart();   // Restart the timer
}

/**
 * Get the elapsed time from the timer.
 * @return The elapsed time in milliseconds.
 */
unsigned long Clock::getTime() {
  return _timer.getTime();
}

/**
 * Get the progress of the current mode as a float between 0.0 and 1.0.
 * @return The progress of the current mode.
 */
float Clock::getProgress() {
  float progress = 0.0;
  if(_mode == WORK_MODE || _prevMode == IDLE_MODE || _prevMode == WORK_MODE) {
    // Calculate progress for work mode
    progress = 1.0 - (float)( _timer.getTime()) / (float)_workTime;
  } else {
    // Calculate progress for break mode
    progress = (float)( _timer.getTime()) / (float)_breakTime;
  }
  progress = constrain(progress, 0.0, 1.0); // Ensure progress is within bounds
  return progress;
}

/**
 * Check if the clock is running.
 * @return True if the clock is running, false otherwise.
 */
bool Clock::isRunning() {
  float progress = getProgress();
  return _mode != IDLE_MODE && progress < 1.0 && progress > 0.0;
}

/**
 * Check if the clock is paused.
 * @return True if the clock is in IDLE_MODE, false otherwise.
 */
bool Clock::isPaused() {
  return _mode == IDLE_MODE;
}

/**
 * Check if the clock has completed its current mode.
 * @return True if the clock is complete, false otherwise.
 */
bool Clock::isComplete() {
  float progress = getProgress();
  return _mode != IDLE_MODE && (progress >= 1.0 || progress <= 0.0);
}
