#include "common.h"

extern s32 D_0021EDD4;
extern char D_306DC0[];
extern void func_0049B148(s32 arg0, s32 arg1);

/* Pick slot arg0 (slot 0 while D_0021EDD4 is zero); if its word 4 differs from arg1, push the old word 4 into the slot's list, bump the count and call func_0049B148. */
void func_0049B1A0(s32 arg0, s32 arg1) {
    s32 idx;
    s32 *ent;
    s32 old;

    idx = ((D_0021EDD4 ^ 1) != 0) ? 0 : arg0;
    ent = (s32 *)(D_306DC0 + idx * 0x3C);
    old = ent[1];
    if (old != arg1) {
        ((s32 *)((s32)ent + (ent[3] << 2)))[4] = old;
        ent[3] = ent[3] + 1;
        func_0049B148(idx, arg1);
    }
}
