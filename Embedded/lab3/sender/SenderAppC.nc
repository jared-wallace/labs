#include <Timer.h>
#include "Sender.h"
 
configuration SenderAppC {
}

implementation {
  components MainC, LedsC;
  components new TimerMilliC() as TimerC;
  components ActiveMessageC as AMsgC;
  components new AMSenderC(RADIOID);
  components SenderC as AppC;

  AppC.Boot -> MainC.Boot;
  AppC.Leds -> LedsC.Leds;
  AppC.Timer -> TimerC.Timer;
  AppC.Packet -> AMSenderC.Packet;
  AppC.AMSend -> AMSenderC.AMSend;
  AppC.SplitControl -> AMsgC.SplitControl;
}
 
