#include "Arduino.h"
#include "ModeSwitch.h"

/**
 * Constructor to initialize ModeSwitch object with default modes
 */
ModeSwitch::ModeSwitch() {
  _mode = IDLE_MODE;
  _prevMode = IDLE_MODE;
}

/**
 * Function to attach pins for work and break modes and set them as input with pull-up resistors
 * @param workPin - Pin number for work mode
 * @param breakPin - Pin number for break mode
 */
void ModeSwitch::attach(int workPin, int breakPin) {
  _workPin = workPin;
  _breakPin = breakPin;

  pinMode(_breakPin, INPUT_PULLUP);
  pinMode(_workPin, INPUT_PULLUP);
}

/**
 * Function to set callback function for when idle mode starts
 * @param callback - Function to call when idle mode starts
 */
void ModeSwitch::onStartIdle(ModeCallback callback)   { _startIdleCallback = callback; }

/**
 * Function to set callback function for when work mode starts
 * @param callback - Function to call when work mode starts
 */
void ModeSwitch::onStartWork(ModeCallback callback)   { _startWorkCallback = callback; }

/**
 * Function to set callback function for when break mode starts
 * @param callback - Function to call when break mode starts
 */
void ModeSwitch::onStartBreak(ModeCallback callback)  { _startBreakCallback = callback; }

/**
 * Function to set callback function for when work mode resumes
 * @param callback - Function to call when work mode resumes
 */
void ModeSwitch::onResumeWork(ModeCallback callback)  { _resumeWorkCallback = callback; }

/**
 * Function to set callback function for when break mode resumes
 * @param callback - Function to call when break mode resumes
 */
void ModeSwitch::onResumeBreak(ModeCallback callback) { _resumeBreakCallback = callback; }

/**
 * Function to update the current mode based on the state of the pins
 */
void ModeSwitch::update() {
  if(digitalRead(_breakPin) == LOW) { // If the break pin is LOW, switch to break mode
    if(_mode == IDLE_MODE && _prevMode == WORK_MODE) { // Transition from idle to break mode
      if(_startBreakCallback != nullptr) {
        _startBreakCallback(BREAK_MODE); // Call the start break callback if set
      }
    } else if(_mode == IDLE_MODE) { // Resume break mode if already in idle
      if(_resumeBreakCallback != nullptr) {
        _resumeBreakCallback(BREAK_MODE); // Call the resume break callback if set
      }
    }
    _mode = BREAK_MODE;
    _prevMode = _mode;
  } else if(digitalRead(_workPin) == LOW) { // If the work pin is LOW, switch to work mode
    if(_mode == IDLE_MODE && _prevMode == BREAK_MODE) { // Transition from idle to work mode
      if(_startWorkCallback != nullptr) {
        _startWorkCallback(WORK_MODE); // Call the start work callback if set
      }
    } else if(_mode == IDLE_MODE) { // Resume work mode if already in idle
      if(_resumeWorkCallback != nullptr) {
        _resumeWorkCallback(WORK_MODE); // Call the resume work callback if set
      }
    }
    _mode = WORK_MODE;
    _prevMode = _mode;
  } else { // If neither pin is LOW, switch to idle mode
    if(_mode != IDLE_MODE) { // Enter idle mode from any other mode
      if(_startIdleCallback != nullptr) {
        _startIdleCallback(IDLE_MODE); // Call the start idle callback if set
      }
    }
    _mode = IDLE_MODE;
  }
}

/**
 * Function to get the current mode
 * @return Current mode
 */
int ModeSwitch::getMode() {
  return _mode;
}

/**
 * Function to get the previous mode
 * @return Current mode
 */
int ModeSwitch::getPrevMode() {
  return _prevMode;
}