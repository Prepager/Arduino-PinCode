// Include guard.
#ifndef PIN_CODE_H
#define PIN_CODE_H

// Define pin code length.
#define PIN_LENGTH 4

// Include Arduino library.
#include <Arduino.h>

// Start class declaration.
class PinCode {
    public:
        PinCode(char * pin);
        void setPin(char * pin);

        bool granted = false;
        bool incorrect = false;

        void addInput(char input);
        void undoInput();

        bool login();
        bool isValid();
        void clearAttempt();

        void clear();

    private:
        int pinLength = PIN_LENGTH;

        int tick = 0;
        char * pin = {'\0'};
        char attempt[PIN_LENGTH] = {'\0'};
};

#endif
