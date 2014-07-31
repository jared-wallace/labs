#include "sensor.h"

module SensorC {
  uses {
    interface Boot;
    interface Leds;
    interface Timer<TMilli>;
    interface Read<uint16_t>;
  }
}

implementation {

  event void Boot.booted() {
    call Timer.startPeriodic(2000);
  }
  
  event void Timer.fired() {
    call Read.read();
  }
  
  event void Read.readDone(error_t result, uint16_t val) {
  }

}
