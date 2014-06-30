#include "sensor.h"

module ForwarderC {
  uses {
    interface Boot;
    interface Leds;
    interface AMSend;
    interface Receive;
    interface SplitControl;
    interface CC2420Packet;
  }
}

implementation {

  message_t pkt;
  
  event void Boot.booted() {
    call SplitControl.start();
  }
  
  event void SplitControl.startDone(error_t error) {
    if (error!=SUCCESS) call SplitControl.start();
  }
  
  event void SplitControl.stopDone(error_t error) {}

  event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
    SenseMsg *sm, *rm;
    call Leds.led1On();
    sm=(SenseMsg*)(call AMSend.getPayload(&pkt, sizeof(SenseMsg)));
    rm=(SenseMsg*)payload;
    sm->sender_id=rm->sender_id;
    sm->cnt=rm->cnt;
    sm->val=rm->val;
    sm->fwd_id=TOS_NODE_ID;
    sm->rec_id=1;
    call CC2420Packet.setPower(&pkt,3);
    call AMSend.send(ReceiverID, &pkt, sizeof(SenseMsg));
    return msg;
  }

  event void AMSend.sendDone(message_t *msg, error_t error) {
    call Leds.led1Off();
  }

}
