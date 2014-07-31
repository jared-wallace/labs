#ifndef SENDEMO_H
#define SENDEMO_H

enum {
  RADIOID = 6,
};

typedef nx_struct SenseMsg {
  nx_uint8_t cnt;
  nx_uint16_t val;
} SenseMsg;

#endif // SENDEMO_H
