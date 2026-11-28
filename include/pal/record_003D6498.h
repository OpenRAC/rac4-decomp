#ifndef PAL_RECORD_003D6498_H
#define PAL_RECORD_003D6498_H

#include "common.h"

typedef struct {
    u8 f0, f1, f2, f3;
    u16 f4, f6, f8, fA, fC;
    u8 fE, fF;
} PalRecord003D6498;

extern PalRecord003D6498 D_003D6498[][8];

#endif
