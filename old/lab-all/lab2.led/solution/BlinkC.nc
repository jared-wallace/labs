#include "Timer.h"  // including header file

// this is the module that describe the interfaces of the component which we wired in BlinkAppC.nc file

module BlinkC
{
  uses interface Timer<TMilli>;     // TMilli is a configuration of the interface Timer
  uses interface Leds;
  uses interface Boot;
}
implementation
{
  uint8_t cnt;
  uint8_t a[] = {0, 1, 3, 2, 6, 7, 5, 4};

  event void Boot.booted()                    // booting the sensor
  {
    cnt = 0;
    call Timer.startPeriodic(1000);           //start the timer with a period of 1000 milli seconds
  }

  event void Timer.fired()                     // every 1000 milli second the following event gets fired 
  {
    call Leds.set(a[cnt%8]);
    cnt++;
  }
  
}

