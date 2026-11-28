#ifndef PAL_MENU_SESSION_H
#define PAL_MENU_SESSION_H

#include "common.h"

typedef struct PalMenuSession PalMenuSession;
struct PalMenuSession {
    u8 pad[0x8C];
    s32 f8C;
    u8 pad90[8];
    s32 f98;
    u64 fA0;
    void *fA8;
    u8 padAC[0x10];
    s32 fBC;
    u8 padC0[4];
    PalMenuSession *fC4;
    PalMenuSession *fC8;
    u8 padCC[4];
};

#endif
