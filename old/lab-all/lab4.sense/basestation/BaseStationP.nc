#include "sensor.h"

module BaseStationP {
  uses {
    interface Boot;
    interface SplitControl as RadioControl;
    interface SplitControl as SerialControl;
    interface Receive as RadioReceive;
    interface AMSend as SerialSend;
    interface Leds;
  }
}

implementation
{

  uint16_t val;

  event void Boot.booted() {
    call RadioControl.start();
    call SerialControl.start();
  }

  event void RadioControl.startDone(error_t error) {
    if (error != SUCCESS) call RadioControl.start();
  }

  event void SerialControl.startDone(error_t error) {
    if (error != SUCCESS) call SerialControl.start();
  }

  event void SerialControl.stopDone(error_t error) {}

  event void RadioControl.stopDone(error_t error) {}

  event message_t * RadioReceive.receive(message_t *msg, void *payload, uint8_t len) {
    call SerialSend.send(0, msg, sizeof(SenseMsg));
    return msg;
  }

  event void SerialSend.sendDone(message_t *msg, error_t error) {
  }

}  
