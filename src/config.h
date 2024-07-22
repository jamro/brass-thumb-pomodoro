#ifndef config_h
#define config_h

#include "Arduino.h";

// CONFIGURATION -------------------------------------------------------
// duration of work phase
constexpr unsigned long WORK_TIME = 1500000; // 25 min
// duration of break phase
constexpr unsigned long BREAK_TIME = 300000; // 5 min
// far right position of the gauge which cause the thumbs up to pop up
constexpr float POP_POS = 3;
// right end position of the scale (not causing the thumbs up to pop up yet)
constexpr float MIN_POS = 25;
// beginning of the scale on the left end
constexpr float MAX_POS = 178;
// pin where servo's control pin is connected
constexpr int SERVO_PIN = 9;
// pin where work mode switch is connected
constexpr int WORK_PIN = 3;
// pin where break mode switch is connected
constexpr int BREAK_PIN = 2;
// --------------------------------------------------------------------

#endif