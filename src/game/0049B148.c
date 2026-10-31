#include "common.h"

extern s32 D_0021EDD4;
extern u8 D_306DC0[];
extern void func_0049B078(s32 arg0);

/* Pick slot arg0 (slot 0 while D_0021EDD4 is zero), store arg1 at its word 8, call func_0049B078 with the slot index, then store arg1 at its word 4. */
void func_0049B148(s32 arg0, s32 arg1) {
    s32 idx;
    s32 *ent;

    idx = ((D_0021EDD4 ^ 1) != 0) ? 0 : arg0;
    ent = (s32 *)(D_306DC0 + idx * 0x3C);
    ent[2] = arg1;
    func_0049B078(idx);
    ent[1] = arg1;
}
