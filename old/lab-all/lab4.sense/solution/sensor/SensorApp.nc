configuration SensorApp {}
implementation {
  components SensorC, MainC, LedsC, ActiveMessageC;
  components new PhotoC(), new TimerMilliC(), new AMSenderC(RADIOID);
  
  SensorC.Boot -> MainC.Boot;
  SensorC.Leds -> LedsC.Leds;
  SensorC.Read -> PhotoC.Read;
  SensorC.Timer -> TimerMilliC.Timer;
  SensorC.AMSend -> AMSenderC.AMSend;
  SensorC.SplitControl -> ActiveMessageC.SplitControl;
}
