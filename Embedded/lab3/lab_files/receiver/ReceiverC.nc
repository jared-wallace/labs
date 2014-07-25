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
    if (len == sizeof(RadioMsg)) {
      RadioMsg* rmsg = (RadioMsg*)payload;
      call Leds.set(rmsg->counter);
    }
    return msg; 
  }

}
 
