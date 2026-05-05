#ifndef beeper_h
#define beeper_h

class Beeper{
private:
   int pin;
   unsigned long beep_interval;
   unsigned long starttime;
   unsigned long length;
   unsigned long pause;
   int repeat;
   int currentRepeat;
   bool beeping;
   bool active;
   void startBeep();
   void stopBeep();
public:
   Beeper(int p);
   void beep(unsigned long l, unsigned long p, int r);
   void update();
   bool checkState();
};
#endif
