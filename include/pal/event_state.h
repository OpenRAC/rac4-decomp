#ifndef PAL_EVENT_STATE_H
#define PAL_EVENT_STATE_H

#include "common.h"

typedef struct {
    s32 event;
    u8 pad04[6];
    s16 state;
    u8 pad0C[4];
    s16 notify;
} PalEventState;

extern s16 D_002069FC[];

#endif
