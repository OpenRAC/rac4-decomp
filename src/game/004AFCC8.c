#include "common.h"

extern void func_0049A6B0(s32 arg0, s32 arg1);
extern void func_004AFE30(void);
extern s32 func_00505B20(void);
extern s32 D_3094F8[];

// Claims the next free slot of D_3094F8 (stride 0x28), clears its word 1, and calls func_0049A6B0 with the slot index and 0x80.
void func_004AFCC8(void) {
    s32 idx;
    s32 *ent;

    idx = func_00505B20();
    ent = (s32 *)((s8 *)D_3094F8 + idx * 0x28);
    func_004AFE30();
    ent[1] = 0;
    func_0049A6B0(idx, 0x80);
}
