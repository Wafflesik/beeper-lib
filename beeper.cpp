#include "beeper.h"
#include "Arduino.h"

Beeper::Beeper(int p){
    pin = p;
    pinMode(pin, OUTPUT);
    active = false;
    beeping = false;
    currentRepeat = 0;
    stopBeep();
}

void Beeper::startBeep(){
    tone(pin, 100);
}

void Beeper::stopBeep(){
    tone(pin, 0);
}


void Beeper::beep(unsigned long l, unsigned long p, int r){
    length = l;
    pause = p;
    repeat = r;
    beep_interval = l + p;
    currentRepeat = 0;
    active = true;
    beeping = true;
    starttime = millis();
    startBeep();
}

void Beeper::update(){
    if (!active) return;

    unsigned long elapsed = millis() - starttime;

    if (beeping){
        // Currently in the ON phase — check if it's time to stop
        if (elapsed >= length){
            stopBeep();
            beeping = false;
            starttime = millis(); // reset timer for the pause phase
        }
    } else {
        // Currently in the pause phase — check if it's time for next beep
        if (elapsed >= pause){
            currentRepeat++;
            if (currentRepeat >= repeat){
                active = false; // all repeats done
            } else {
                startBeep();
                beeping = true;
                starttime = millis();
            }
        }
    }
}

bool Beeper::checkState(){
    return active;
}
