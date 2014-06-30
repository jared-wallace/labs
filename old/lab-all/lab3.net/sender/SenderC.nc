#include <Timer.h>
#include "Sender.h"
 
module SenderC {
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli>;
  uses interface Packet;
  uses interface AMSend;
  uses interface SplitControl;
}

implementation {
  message_t pkt;
  uint16_t cnt;

  event void Boot.booted() {
    call SplitControl.start();
    cnt = 0;
  }
   
  event void SplitControl.startDone(error_t err) {
    if (err == SUCCESS) call Timer.startPeriodic(TIMER_PERIOD_MILLI);
    else call SplitControl.start();
  }
  
  event void SplitControl.stopDone(error_t err) {}

  event void Timer.fired() {
    RadioMsg* rmsg = (RadioMsg*)(call Packet.getPayload(&pkt, sizeof(RadioMsg)));
    rmsg->nodeid = TOS_NODE_ID;
    rmsg->counter = cnt;
    call AMSend.send(ReceiverID, &pkt, sizeof(RadioMsg));
    cnt++;
  }

  event void AMSend.sendDone(message_t* msg, error_t error) {
    call Leds.led0Toggle();
  }
 
}
 
