#ifndef ModeSwitch_h
#define ModeSwitch_h

#include "Arduino.h"

// Constants to define the different modes
constexpr int WORK_MODE = 1;
constexpr int BREAK_MODE = 2;
constexpr int IDLE_MODE = 0;

// Type definition for the callback functions
typedef void (*ModeCallback)(int);

/**
 * ModeSwitch class to manage the state transitions between different modes.
 * Provides functionality to attach pins, update modes, and set callbacks for mode changes.
 */
class ModeSwitch {
  public:
    /**
     * Constructor to initialize ModeSwitch object with default modes.
     */
    ModeSwitch();

    /**
     * Attach pins for work and break modes and set them as input with pull-up resistors.
     * @param workPin - Pin number for work mode
     * @param breakPin - Pin number for break mode
     */
    void attach(int workPin, int breakPin);

    /**
     * Update the current mode based on the state of the pins.
     */
    void update();

    /**
     * Get the current mode.
     * @return The current mode (WORK_MODE, BREAK_MODE, or IDLE_MODE).
     */
    int getMode();

    /**
     * Get the previous mode.
     * @return The previous mode before the current transition.
     */
    int getPrevMode();

    /**
     * Set the callback function to be called when idle mode starts.
     * @param callback - Function to call when idle mode starts.
     */
    void onStartIdle(ModeCallback callback);

    /**
     * Set the callback function to be called when work mode starts.
     * @param callback - Function to call when work mode starts.
     */
    void onStartWork(ModeCallback callback);

    /**
     * Set the callback function to be called when break mode starts.
     * @param callback - Function to call when break mode starts.
     */
    void onStartBreak(ModeCallback callback);

    /**
     * Set the callback function to be called when work mode resumes.
     * @param callback - Function to call when work mode resumes.
     */
    void onResumeWork(ModeCallback callback);

    /**
     * Set the callback function to be called when break mode resumes.
     * @param callback - Function to call when break mode resumes.
     */
    void onResumeBreak(ModeCallback callback);

  private:
    int _mode;                        // Current mode (WORK_MODE, BREAK_MODE, or IDLE_MODE)
    int _prevMode;                    // Previous mode before the current transition
    int _workPin;                     // Pin number for work mode
    int _breakPin;                    // Pin number for break mode
    ModeCallback _startIdleCallback;  // Callback for starting idle mode
    ModeCallback _startWorkCallback;  // Callback for starting work mode
    ModeCallback _startBreakCallback; // Callback for starting break mode
    ModeCallback _resumeWorkCallback; // Callback for resuming work mode
    ModeCallback _resumeBreakCallback;// Callback for resuming break mode
};

#endif
