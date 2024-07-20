#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

/**
 * Timer class to manage timing sequences.
 * Provides functionality to start, stop, restart, and get the elapsed time.
 */
class Timer {
  public: 
    /**
     * Constructor to initialize Timer object with default values.
     */
    Timer();
    
    /**
     * Start the timer if it is not already running.
     * Records the current time as the start time of the timing sequence.
     */
    void start();
    
    /**
     * Stop the timer if it is running.
     * Adds the elapsed time since the timer started to the total elapsed time.
     */
    void stop();
    
    /**
     * Restart the timer. Resets the total elapsed time and starts the timer.
     * Records the current time as the start time of the new timing sequence.
     */
    void restart();
    
    /**
     * Get the total elapsed time in milliseconds.
     * If the timer is running, includes the time elapsed in the current sequence.
     * @return The total elapsed time in milliseconds.
     */
    unsigned long getTime();

  private:
    unsigned long _time;           // Total accumulated time in milliseconds
    unsigned long _sequenceStart;  // The start time of the current timing sequence
    bool _running;                 // Boolean flag to indicate if the timer is running
};

#endif
