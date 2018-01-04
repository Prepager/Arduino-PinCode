# Arduino - Single Pin Code
This library provides a super simple single pin code system supporting chars.

## Methods
``PinCode::PinCode(char * pin)`` _Sets pin based on pointer on init._

``void PinCode::setPin(char * pin)`` _Sets the pin code for further use._

``void PinCode::addInput(char input)``_Adds a single char to the current attempt._

``void PinCode::undoInput()`` _Removes the most recent char from the attempt._

``bool PinCode::login()`` _Match attempt and pin code and returns state._

``bool PinCode::isValid()`` _Validates the correct amount of chars in attempt._

``void PinCode::clearAttempt()`` _Clears out the current attempt inputs._

``void PinCode::clear()`` _Resets all variables except for the pin code._

## Variables
``#define PIN_LENGTH 4`` _The amount of chars in the pin code._

``bool granted = false`` _The current granted state._

``bool incorrect = false`` _The current incorrect state._

## Usage
```cpp
// Include the PinCode file.
#include "PinCode.h"

// Create a new PinCode object with pin.
char pinCode[4] = {'1','2','3','4'};
PinCode pin(pinCode);

void setup() {
    Serial.begin(9600);

    // Add three inputs to object.
    pin.addInput('1');
    pin.addInput('2');
    pin.addInput('4');

    // Remove most recent input.
    pin.undoInput();

    // Add last two inputs.
    pin.addInput('3');
    pin.addInput('4');

    // Validate correct amount of inputs and login.
    if (pin.isValid() && pin.login()) {
        // Output message and granted status.
        Serial.println("Access granted!");
        Serial.println(pin.granted);

        // Clear current granted status.
        pin.clear();
    } else {
        // Output message and incorrect status.
        Serial.println("Login failed!");
        Serial.println(pin.incorrect);
    }
}
```
