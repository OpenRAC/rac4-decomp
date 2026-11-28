#ifndef PAL_MOBY_CLASS_H
#define PAL_MOBY_CLASS_H

#include "common.h"

typedef struct {
    u8 pad00[0xBC];
    s16 classId;
    u8 padBE[0x42];
} PalMobyClassView;

#endif
