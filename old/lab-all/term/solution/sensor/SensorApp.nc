configuration SensorApp {}
implementation {
  components SensorC, ForwarderC, MainC, LedsC, ActiveMessageC as AMsgC, CC2420PacketC;
//  components new PhotoC(), new TimerMilliC() as TimerC, new AMSenderC(AM_SENSEMSG) as SensorSenderC;
//  components new AMSenderC(AM_SENSEMSG) as ForwarderSenderC, new AMReceiverC(AM_SENSEMSG) as ForwarderReceiverC;
  components new PhotoC(), new TimerMilliC() as TimerC, new AMSenderC(AM_SENSEMSG), new AMReceiverC(AM_SENSEMSG);
  
  SensorC.Boot -> MainC.Boot;
  SensorC.Leds -> LedsC.Leds;
  SensorC.Read -> PhotoC.Read;
  SensorC.Timer -> TimerC.Timer;
  SensorC.AMSend -> AMSenderC.AMSend;
  SensorC.SplitControl -> AMsgC.SplitControl;
  SensorC.CC2420Packet -> CC2420PacketC.CC2420Packet;

  ForwarderC.Boot -> MainC.Boot;
  ForwarderC.Leds -> LedsC.Leds;
  ForwarderC.AMSend -> AMSenderC.AMSend;
  ForwarderC.Receive -> AMReceiverC.Receive;
  ForwarderC.SplitControl -> AMsgC.SplitControl;
  ForwarderC.CC2420Packet -> CC2420PacketC.CC2420Packet;
}
 
