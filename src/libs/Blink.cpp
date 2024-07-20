#include "Arduino.h"
#include "Blink.h"

/**
 * Constructor to initialize Blink object with default values.
 * Sets the default on and off periods, LED pin, and time.
 */
Blink::Blink() {
  _onPeriod = 4;
  _offPeriod = 4;
  _ledPin = 13;
  _time = 0;
}

/**
 * Attach a specific LED pin to the Blink object and set it as output.
 * @param ledPin - The pin number where the LED is connected.
 */
void Blink::attach(int ledPin) {
  _ledPin = ledPin;
  pinMode(_ledPin, OUTPUT); // Set the LED pin as an output
}

/**
 * Set the on and off periods to the same value.
 * @param onTime - The number of cycles for which the LED should be on and off.
 */
void Blink::setPeriod(int onTime) {
  _onPeriod = onTime;
  _offPeriod = onTime;
}

/**
 * Set the on and off periods to different values.
 * @param onTime - The number of cycles for which the LED should be on.
 * @param offTime - The number of cycles for which the LED should be off.
 */
void Blink::setPeriod(int onTime, int offTime) {
  _onPeriod = onTime;
  _offPeriod = offTime;
}

/**
 * Update the LED state based on the current time and periods.
 * This function should be called in the main loop to blink the LED.
 */
void Blink::step() {
  if(_onPeriod == 0) { 
    digitalWrite(_ledPin, LOW); // Turn off the LED if the on period is 0
    _time = 0;
    return;
  }

  if(_time < _onPeriod) {
    digitalWrite(_ledPin, HIGH); // Turn on the LED during the on period
    _time++;
  } else if(_time < _onPeriod + _offPeriod) {
    digitalWrite(_ledPin, LOW); // Turn off the LED during the off period
    _time++;
  } else {
    _time = 0; // Reset the time counter after the total period
  }
}
