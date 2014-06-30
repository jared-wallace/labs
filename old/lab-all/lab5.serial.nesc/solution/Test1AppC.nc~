configuration Test1AppC {}
implementation {
  components Test1C, MainC, LedsC, SerialActiveMessageC, new SerialAMSenderC(0);

  Test1C.Boot -> MainC.Boot;
  Test1C.Leds -> LedsC.Leds;
  Test1C.AMSend -> SerialAMSenderC.AMSend;
  Test1C.SplitControl -> SerialActiveMessageC.SplitControl;
}
