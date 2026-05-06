#ifndef beeper_h
#define beeper_h

class Beeper{
private:
   int _pin;
   unsigned long _beep_interval;
   unsigned long _starttime;
   unsigned long _length;
   unsigned long _pause;
   int _repeat;
   int _currentRepeat;
   bool _beeping;
   bool _isPaused;
   void startBeep();
   void stopBeep();
public:
   Beeper(int p);
   void beep(unsigned long lenght, unsigned long pause, int repeat);
   void update();
   bool checkState();
};
#endif
