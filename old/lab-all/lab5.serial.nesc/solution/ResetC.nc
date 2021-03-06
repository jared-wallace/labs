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
  
  void light(uint8_t x) {
    if (x == 0) {
      call Leds.led0On();
      call Leds.led1Off();
      call Leds.led2Off();
    } else if (x == 1) {
      call Leds.led0Off();
      call Leds.led1On();
      call Leds.led2Off();
    } else if (x == 2) {
      call Leds.led0Off();
      call Leds.led1Off();
      call Leds.led2On();
    } else if (x == 3) {
      call Leds.led0On();
      call Leds.led1Off();
      call Leds.led2On();
    } else {
      call Leds.led0On();
      call Leds.led1On();
      call Leds.led2On();
    }
  }
  
  void usartsend(uint8_t x) {
    uint8_t* m;
    m=(uint8_t*)(call AMSend.getPayload(&pkt, 1));
    *m=x;
    call AMSend.send(0, &pkt, 1);
  }
  
  event void Boot.booted() {
    call SplitControl.start();
  }
  
  event void SplitControl.startDone(error_t error) {
    uint8_t* x;
    if (error!=SUCCESS) call SplitControl.start();
    else {
      x=(uint8_t*)0x0400;
      *x=*x+1;
      light((*x)%4);
      usartsend(*x);
    }
  }
  
  event void SplitControl.stopDone(error_t error) {}
  
  event void AMSend.sendDone(message_t *msg, error_t error) {}
  
}
