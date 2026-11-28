#ifndef PAL_MENU_HANDOFF_H
#define PAL_MENU_HANDOFF_H

#include "common.h"

typedef struct PalMenuHandoffChild PalMenuHandoffChild;

typedef struct {
    u8 pad[0x140];
    void (*refresh)(PalMenuHandoffChild *);
} PalMenuHandoffMethods;

struct PalMenuHandoffChild {
    u8 pad00[0x58];
    PalMenuHandoffMethods *methods;
    u8 pad5C[0x4C];
    u8 fA8;
    u8 fA9;
    u8 padAA[0x1A6];
    s32 f250;
    s32 f254;
    u8 pad258[0xC];
    u8 f264;
};

extern u8 D_00220AD0;
extern u8 D_00220AD1;

#endif
