//begining of the configuration file

configuration BlinkAppC
{
}
implementation
{
  components MainC, BlinkC, LedsC;          // LedsC for controlling Leds, MainC for booting,
                                            // and also BlinkC defined in main file BlinkC.nc
  components new TimerMilliC() as TimerC;   // this component has an alias name TimerC


  BlinkC.Boot -> MainC.Boot;                // wiring BlinkC to Main
  BlinkC.Timer -> TimerC.Timer;             // wiring BlinkC to TimerC
  BlinkC.Leds -> LedsC.Leds;                // wiring BlinkC to LedsC
}

