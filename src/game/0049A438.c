#include "common.h"

typedef struct { u8 f0; u8 active; u8 pad2[2]; s32 f4; s32 f8; s32 fC; } Slot;
typedef struct { s32 f0; void (*on8)(s32); void (*onC)(s32); } Entry;

extern void func_00497FE8(s32 arg0, s32 arg1);
extern s32 func_0049A068(s32 index);
extern s32 func_0049A3A8(s32 index);
extern s32 func_0049A3E0(s32 index);
extern void func_0049A810(s32 context);
extern void func_0049B148(s32 arg0, s32 arg1);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern s32 func_00505C08(s32 arg0);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern Entry D_003D8DE0[];
extern s32 D_00221580;
extern Slot D_00306D20[];

void func_0049A438(s32 arg0)
{
    s32 idx = func_00505B20();
    Slot *s = &D_00306D20[idx];
    s32 diff;
    s32 i;
    Entry *e;

    if (idx == 0 && D_00221580 > 0) {
        D_00221580--;
    }
    if (func_0049A3A8(idx) && func_0049A3E0(idx)) {
        if (D_0021EDD4 == 1) {
            func_0049B148(idx, 1);
            func_00497FE8(idx, 2);
        } else if (D_0021EDD4 != 0 || D_0021EDD8 != 1 || func_0049A3A8(idx == 0)) {
            func_0049B148(0, 1);
            func_00497FE8(0, 2);
        }
    }
    if (s->active) {
        func_0049A810(idx);
        func_00505C08(func_0049A068(idx));
        func_005014B0(arg0);
        s->active = 0;
        return;
    }
    if ((s->f8 & ~s->fC) == s->f4) {
        return;
    }
    diff = s->f8 ^ s->f4;
    e = D_003D8DE0;
    for (i = 0; i < 11; i++, e++) {
        s32 bit = 1 << i;
        if (diff & bit) {
            if (s->f4 & bit) {
                s->f8 |= bit;
                if (e->on8) {
                    e->on8(idx);
                }
            } else if (!(s->fC & bit)) {
                s->fC |= bit;
                if (e->onC) {
                    e->onC(idx);
                }
            }
        }
    }
}
