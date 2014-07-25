#ifndef SENDER_H
#define SENDER_H
 
enum {
  RADIOID = 6,
  TIMER_PERIOD_MILLI = 1000,
  ReceiverID = 2,
};
 
typedef nx_struct _RadioMsg {
  nx_uint16_t nodeid;
  nx_uint16_t counter;
} RadioMsg;
  
 #endif
