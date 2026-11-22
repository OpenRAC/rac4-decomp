#include "common.h"
typedef struct { u8 pad[0x94]; s32 idx; } A;
typedef struct { u8 pad[0x86]; s16 id; } B;
typedef struct { u8 pad[0xFC]; s32 f; } Sub;
typedef struct { u8 pad[0x150]; Sub sub; u8 pad2[0x468 - 0x150 - 0x100]; s32 g; u8 pad3[0x470 - 0x46C]; } Slot;
extern s32 D_0021DDB4;
extern s32 D_00222B84;
extern Slot D_00230280[];
s32 func_L01_00524E58(A *a, B *b)
{
    Slot *s = &D_00230280[a->idx];
    Sub *q = &s->sub;
    if (D_0021DDB4 == 0 && q->f == 0x20 && b->id == 0) {
        if (D_00222B84 < 2) {
            s->g = 1;
        }
        return 1;
    }
    return 0;
}
