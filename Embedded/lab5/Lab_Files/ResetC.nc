#include "Serial.h"

module ResetC {
  uses {
    interface Leds;
    interface Boot;
    interface AMSend;
    interface SplitControl;
  }
}
   
implementation {

  message_t pkt;
  
  event void Boot.booted() {
    call SplitControl.start();
  }
  
  event void SplitControl.startDone(error_t error) {}
  
  event void SplitControl.stopDone(error_t error) {}
  
  event void AMSend.sendDone(message_t *msg, error_t error) {}
  
}
