#include "sensor.h"

module SensorC {
  uses {
    interface Boot;
    interface Leds;
    interface Timer<TMilli>;
    interface Read<uint16_t>;
    interface AMSend;
    interface SplitControl;
  }
}

implementation {

  uint8_t cnt;
  message_t pkt;
  uint16_t valsum;
  
  event void Boot.booted() {
    cnt=0;
    valsum=0;
    call SplitControl.start();
  }
  
  event void SplitControl.startDone(error_t error) {
    if (error==SUCCESS) call Timer.startPeriodic(2000);
    else call SplitControl.start();    
  }
  
  event void Timer.fired() {
    call Read.read();
  }
  
  event void Read.readDone(error_t result, uint16_t val) {
    SenseMsg* sm;
    call Leds.led0On(); // red
    if (val>=0x180) {   // green
       call Leds.led1On();
       call Leds.led2Off();
    } else {            // yellow
       call Leds.led1Off();
       call Leds.led2On();
    }
    valsum+=val;
    if (cnt%3==0) {
      val=valsum/3;
      valsum = 0;
      sm=(SenseMsg*)(call AMSend.getPayload(&pkt, sizeof(SenseMsg)));
      sm->cnt=cnt;
      sm->val=val;
      call AMSend.send(ReceiverID, &pkt, sizeof(SenseMsg));
    }
    cnt++;
  }
  
  event void AMSend.sendDone(message_t *msg, error_t error) {
    call Leds.led0Off();
  }
  
  event void SplitControl.stopDone(error_t error) {}

}
