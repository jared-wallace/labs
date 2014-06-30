#include <Timer.h>
#include "Sender.h"
 
module SenderC {
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli>;
  uses interface Packet;
  uses interface AMSend;
  uses interface SplitControl;
  uses interface PacketAcknowledgements as Acks;
}

implementation {
  message_t pkt;
  uint16_t cnt;
  uint16_t cmd[] = {0, 2, 4, 6, 8};

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
    rmsg->counter = cmd[cnt%5];
    call Acks.requestAck(&pkt);
    call AMSend.send(ReceiverID, &pkt, sizeof(RadioMsg));
    cnt++;

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

  }

  event void AMSend.sendDone(message_t* msg, error_t error) {
    if (!call Acks.wasAcked(msg)) {
      call Acks.requestAck(msg);
      call AMSend.send(ReceiverID, msg, sizeof(RadioMsg));
    }
  }
 
}
 
