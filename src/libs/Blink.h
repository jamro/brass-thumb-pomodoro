#ifndef Blink_h
#define Blink_h

#include "Arduino.h"

/**
 * Blink class to manage the blinking of an LED.
 * Provides functionality to attach an LED pin, set blink periods, and update the LED state.
 */
class Blink {
  public:
    /**
     * Constructor to initialize Blink object with default values.
     */
    Blink();

    /**
     * Attach a specific LED pin to the Blink object and set it as output.
     * @param ledPin - The pin number where the LED is connected.
     */
    void attach(int ledPin);

    /**
     * Update the LED state based on the current time and periods.
     * This function should be called in the main loop to blink the LED.
     */
    void step();

    /**
     * Set the on and off periods to the same value.
     * @param onTime - The duration for which the LED should be on and off.
     */
    void setPeriod(int onTime);

    /**
     * Set the on and off periods to different values.
     * @param onTime - The number of cycles for which the LED should be on.
     * @param offTime - The number of cycles for which the LED should be off.
     */
    void setPeriod(int onTime, int offTime);

  private:
    int _onPeriod;   // The number of cycles for which the LED should be on
    int _offPeriod;  // The number of cycles for which the LED should be off
    int _ledPin;     // Pin number where the LED is connected
    int _time;       // Time counter to track the current state within the period
};

#endif
