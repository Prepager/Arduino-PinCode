// Include header file.
#include "PinCode.h"

/**
 * Set pin on init from arguments. 
 *
 * @param  char*  pin
 */
PinCode::PinCode(char * pin) {
    this->setPin(pin);
}

/**
 * Set pin code pointer.
 *
 * @param  char*  pin
 */
void PinCode::setPin(char * pin) {
    this->pin = pin;
}

/**
 * Add an input to the attempt.
 *
 * @param  char  input
 */
void PinCode::addInput(char input) {
    // Prevent tick overflow.
    if (this->tick == PIN_LENGTH)
        return;

    // Add the input to the array.
    this->attempt[this->tick] = input;

    // Increment current tick.
    this->tick++;
}

/**
 * Remove the latest input from the attempt.
 */
void PinCode::undoInput() {
    // Decrease by one if not 0.
    if (this->tick != 0)
        this->tick -= 1;
}

/**
 * Attempt to login and return result.
 *
 * @return bool
 */
bool PinCode::login() {
    // Clear attempts.
    this->clearAttempt();

    // Loop through the pin length.
    for(int i = 0; i < this->pinLength; i++) {
        // Check if values are not equal.
        if (this->attempt[i] != this->pin[i]) {
            // Activate incorrect and return out.
            this->incorrect = true;
            return false;
        }
    }

    // Active granted and deactivate incorrect.
    this->granted = true;
    this->incorrect = false;

    // Return true for success.
    return true;
}

/**
 * Check if the pin has the correct length.
 *
 * @return bool
 */
bool PinCode::isValid() {
    return this->tick == this->pinLength;
}

/**
 * Clear the current attempt.
 */
void PinCode::clearAttempt() {
    this->tick = 0;
}

/**
 * Clear the current attempt and states.
 */
void PinCode::clear() {
    // Reset pin tick.
    this->clearAttempt();

    // Reset granted and incorrect state.
    this->granted = false;
    this->incorrect = false;
}
