#ifndef SENDEMO_H
#define SENDEMO_H

enum {
  AM_SENSEMSG = 1,
};

typedef nx_struct SenseMsg {
  nx_uint16_t sender_id;
  nx_uint16_t cnt;
  nx_uint16_t val;
  nx_uint16_t fwd_id;
  nx_uint16_t rec_id;
} SenseMsg;

#endif // SENDEMO_H
