#include <Servo.h>
#include "libs/ModeSwitch.h"
#include "libs/Blink.h"
#include "libs/Clock.h"
#include "config.h"

// Constant for step time delay
constexpr float STEP_TIME = 30;

Servo gaugeServo;        
ModeSwitch modeSwitch;            
Blink blink;             
Clock clock = Clock(WORK_TIME, BREAK_TIME);

float pos = MAX_POS; 

/**
 * Welcome sequence to initialize the servo with a predefined movement.
 */
void welcome() {
  gaugeServo.write(MAX_POS);
  delay(1000);
  gaugeServo.write(POP_POS);
  delay(2000);
  gaugeServo.write(pos);
  delay(1000);
}

/**
 * Arduino setup function, runs once at the start.
 */
void setup() {
  Serial.begin(9600);
  blink.attach(LED_BUILTIN);

  gaugeServo.attach(SERVO_PIN);

  modeSwitch.attach(WORK_PIN, BREAK_PIN);
  modeSwitch.onStartWork(restartClock);
  modeSwitch.onResumeWork(startClock);
  modeSwitch.onStartBreak(restartClock);
  modeSwitch.onResumeBreak(startClock);
  modeSwitch.onStartIdle(stopClock);

  welcome();

  Serial.println("=== CLOCK READY ===");
  blink.setPeriod(0);
}

/**
 * Callback function to restart the clock.
 */
void restartClock(int mode) { clock.restart(mode); }

/**
 * Callback function to start the clock.
 */
void startClock(int mode) { clock.start(mode); }

/**
 * Callback function to stop the clock.
 */
void stopClock() { clock.stop(); }

/**
 * Function to update the clock based on the current mode and time.
 */
void runClock() {
  modeSwitch.update();  // Update the mode switch state
  int mode = modeSwitch.getMode();
  float progress = clock.getProgress();

  pos = MIN_POS + (progress) * (MAX_POS - MIN_POS);

  if(clock.isComplete()) {
    blink.setPeriod(1);
  } else if(clock.isRunning()) {
    blink.setPeriod(1, 1000/STEP_TIME-1);
  } else {
    blink.setPeriod(0);
  }

  if(pos <= MIN_POS && mode == WORK_MODE) {
    pos = POP_POS;
  }

  gaugeServo.write(constrain(pos, 0, 180)); // Write constrained position to servo
}

/**
 * Arduino main loop function, runs repeatedly.
 */
void loop() {
  runClock();
  blink.step();
  delay(STEP_TIME);
}
