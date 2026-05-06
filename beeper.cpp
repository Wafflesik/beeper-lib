#include "beeper.h"
#include "Arduino.h"

Beeper::Beeper(int p){
    _pin = p;
    _isPaused = false;
    _beeping = false;
	_repeat = false;
    _currentRepeat = 0;
    pinMode(pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void Beeper::startBeep(){
    _starttime = millis();
    _beeping = true;
    _isPaused = false;
    digitalWrite(_pin, HIGH);
}

void Beeper::stopBeep(){
    digitalWrite(_pin, LOW);
    _beeping = false;
    
}


void Beeper::beep(unsigned long length, unsigned long pause, int repeat){
    _length = length;
    _pause = pause;
    _currentRepeat = 0;
    _repeat = repeat;
    startBeep();
}

void Beeper::update(){
   	if (_currentRepeat = _repeat) return;

	if (_beeping){
		if (millis() - _starttime >= _length){
			stopBeep();
			_currentRepeat++

			if (_repeat-_currentRepeat >0){
				_isPaused = true;
				_starttime = millis();
			}
		}
	}
	else if (_isPaused){
		if (millis()-starttime >= _pause){
			startBeep();
		}
	}	
}

bool Beeper::checkState(){
    return active;
}
