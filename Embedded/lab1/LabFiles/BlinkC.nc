#include "Timer.h"  // including header file

// this is the module that describe the interfaces of the component which we wired in BlinkAppC.nc file

module BlinkC
{
  uses interface Timer<TMilli> as Timer;     // TMilli is a configuration of the interface Timer
  uses interface Leds;
  uses interface Boot;
}
implementation
{
  uint8_t cnt;

  event void Boot.booted()                    // booting the sensor
  {
    cnt = 0;
    call Timer.startPeriodic(1000);           //start the timer with a period of 1000 milli seconds
  }

  event void Timer.fired()                     // every 1000 milli second the following event gets fired 
  {
    // change the code below to complete A.3 in Lab 1
    cnt++;
    if (cnt%2 == 0) call Leds.led0Toggle();                   //command to toggle led0
    if (cnt%3 == 0) call Leds.led1Toggle();                   //command to toggle led1
    if (cnt%4 == 0) call Leds.led2Toggle();                   //command to toggle led2
  }
  
}

