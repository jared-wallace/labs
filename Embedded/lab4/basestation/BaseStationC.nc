configuration BaseStationC {
}
implementation {
  components MainC, BaseStationP, LedsC;
  components ActiveMessageC, SerialActiveMessageC;
  components new AMReceiverC(RADIOID) as RadioC, new SerialAMSenderC(RADIOID) as SerialC;
  
  BaseStationP.Boot -> MainC.Boot;

  BaseStationP.RadioControl -> ActiveMessageC.SplitControl;
  BaseStationP.SerialControl -> SerialActiveMessageC.SplitControl;
  
  BaseStationP.RadioReceive -> RadioC.Receive;
  BaseStationP.SerialSend -> SerialC.AMSend;

  BaseStationP.Leds -> LedsC.Leds;
}
