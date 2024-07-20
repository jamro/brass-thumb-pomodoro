#include "Arduino.h"
#include "Timer.h"

/**
 * Constructor to initialize Timer object with default values
 */
Timer::Timer() {
  _time = 0;                 
  _sequenceStart = 0;        
  _running = false;
}

/**
 * Start the timer. If the timer is already running, do nothing.
 */
void Timer::start() {
  if(_running) return;
  _running = true;
  _sequenceStart = millis();
}

/**
 * Stop the timer. If the timer is not running, do nothing.
 */
void Timer::stop() {
  if(!_running) return; 
  _running = false;
  _time += millis() - _sequenceStart;
}

/**
 * Restart the timer. Reset the total time and start the timer.
 */
void Timer::restart() {
  _running = true; 
  _time = 0;
  _sequenceStart = millis(); 
}

/**
 * Get the total elapsed time. If the timer is running, include the current sequence time.
 * @return The total elapsed time in milliseconds
 */
unsigned long Timer::getTime() {
  if(_running) {
    return _time + millis() - _sequenceStart; // Return the total time plus the current sequence time
  } else {
    return _time; // Return the total time
  }
}
