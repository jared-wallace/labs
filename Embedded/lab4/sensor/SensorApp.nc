configuration SensorApp {}
implementation {
  components SensorC, MainC, LedsC;
  components new PhotoC(), new TimerMilliC();
  
  SensorC.Boot -> MainC.Boot;
  SensorC.Leds -> LedsC.Leds;
  SensorC.Read -> PhotoC.Read;
  SensorC.Timer -> TimerMilliC.Timer;
}
