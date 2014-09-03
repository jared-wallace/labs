//begining of the configuration file

configuration BlinkAppC
{
}
implementation
{
  components MainC, BlinkC, LedsC;          // using component for Led to turn on (LedsC), MainC for the senser boot function
                                            // and also our defined component which is main file BlinkC.nc
  components new TimerMilliC() as T0;       // this component is used to wire the Timer with the alias name T0 of BlinkC
  components new TimerMilliC() as T1;       // this component is used to wire the with the alias name T1 Timer of BlinkC
  components new TimerMilliC() as T2;       // this component is used to wire the Timer with the alias name T2 of BlinkC


  BlinkC.Boot -> MainC.Boot;                // wiring Main.Boot to BlinkC

  BlinkC.Time0 -> T0.Timer;                 // wiring TimerMillic ie T0 to the BlinkC
  BlinkC.Time1 -> T1.Timer;                 // wiring TimerMillic ie T1 to the BlinkC
  BlinkC.Time2 -> T2.Timer;                 // wiring TimerMillic ie T2 to the BlinkC
  BlinkC.Leds -> LedsC.Leds;                // wiring LedsC to the BlinkC
}

