#ifndef beeper_h
#define beeper_h

class Beeper
{
private:
   int pin;
   int beep_interval;
   unsigned long starttime;
   unsigned long length;
   unsigned long pause;
   int repeat;
   void startBeep();
   void stopBeep();
public:
   Beeper(pin);
   void beep(length, pause, repeat);
   bool checkState();
}
#endif