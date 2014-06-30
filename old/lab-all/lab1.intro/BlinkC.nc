#include "Timer.h"  // including header file

// this is the module that describe the interfaces of the component which we wired in BlinkAppC.nc file

module BlinkC
{
  uses interface Timer<TMilli> as Time0;           //Time0 Alias name for Timer Milli 
  uses interface Timer<TMilli> as Time1;           //Time1 Alias name for Timer Milli 
  uses interface Timer<TMilli> as Time2;           //Time2 Alias name for Timer Milli 
  uses interface Leds;
  uses interface Boot;
}
implementation
{
  event void Boot.booted()                         // booting the sensor
  {
    call Time0.startPeriodic( 250 );               //start the timer and set it 250 milli seconds
    call Time1.startPeriodic( 500 );               //start the timer and set it 500 milli seconds
    call Time2.startPeriodic( 1000 );              //start the timer and set it 1000 milli seconds
  }

  event void Time0.fired()                           // every 250 milli second the following event gets fired 
  {
    call Leds.led0Toggle();                          //command which toggles led 0 
  }
  
  event void Time1.fired()                            // every 250 milli second the following event gets fired 
  {
    call Leds.led1Toggle();                              //command which toggles led 1 
  }
  
  event void Time2.fired()                             // every 250 milli second the following event gets fired 
  {
 
    call Leds.led2Toggle();                               //command which toggles led 2
  }
}

