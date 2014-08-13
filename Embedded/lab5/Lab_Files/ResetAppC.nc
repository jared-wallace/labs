configuration ResetAppC {}
implementation {
  components ResetC, MainC, LedsC, SerialActiveMessageC, new SerialAMSenderC(0);

  ResetC.Boot -> MainC.Boot;
  ResetC.Leds -> LedsC.Leds;
  ResetC.AMSend -> SerialAMSenderC.AMSend;
  ResetC.SplitControl -> SerialActiveMessageC.SplitControl;
}
