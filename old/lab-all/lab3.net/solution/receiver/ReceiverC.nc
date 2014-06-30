#include <Timer.h>
#include "Receiver.h"
 
module ReceiverC {
  uses interface Boot;
  uses interface Leds;
  uses interface Packet;
  uses interface SplitControl;
  uses interface Receive;
}
implementation {

  event void Boot.booted() {
    call SplitControl.start(); 
  }

  event void SplitControl.startDone(error_t err) {
    if (err != SUCCESS) call SplitControl.start();
  }

  event void SplitControl.stopDone(error_t err) {}

  event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
    RadioMsg* rmsg = (RadioMsg*)payload;
    switch (rmsg->counter) {
      case 0:
        call Leds.set(0);
        break;
      case 2:
        call Leds.set(1);
        break;
      case 4:
        call Leds.set(2);
        break;
      case 6:
        call Leds.set(4);
        break;
      case 8:
        call Leds.set(7);
        break;
      default:
        call Leds.set(5);
    }
    return msg; 
  }

}
 
