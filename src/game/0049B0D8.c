#include "common.h"

extern s32 D_0021EDD4;
extern u8 D_306DC0[];
extern void func_0049B018(s32 arg0);

// Pick slot arg0 (slot 0 while D_0021EDD4 is zero), copy its word at 8 to 4, then call func_0049B018 with the slot index.
void func_0049B0D8(s32 arg0) {
    s32 idx;
    s32 *ent;

    idx = ((D_0021EDD4 ^ 1) != 0) ? 0 : arg0;
    ent = (s32 *)(D_306DC0 + idx * 0x3C);
    ent[1] = ent[2];
    func_0049B018(idx);
}
