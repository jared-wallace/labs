#include <Timer.h>
#include "Receiver.h"
 
configuration ReceiverAppC {
}

implementation {
  components MainC;
  components LedsC;
  components ActiveMessageC as AMsgC;
  components new AMReceiverC(RADIOID);
  components ReceiverC as AppC;
 
  AppC.Boot -> MainC.Boot;
  AppC.Leds -> LedsC.Leds;
  AppC.SplitControl -> AMsgC.SplitControl;
  AppC.Receive -> AMReceiverC.Receive;
}
 
