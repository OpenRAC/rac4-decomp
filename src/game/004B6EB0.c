#include "common.h"

extern void func_00497980(s32 arg0);
extern void func_0049B1A0(s32 param, s32 count);
extern s32 func_004A0208(s32 arg0);
extern s32 func_00505B20(void);
extern s32 D_3098F0[];
s8 D_0021F7E8 = 0;

// Stores func_004A0208's result at offset 0 of the 0x1F8-byte slot of D_3098F0 for the current owner, clears D_0021F7E8 and re-registers the owner with count 6.
void func_004B6EB0(void) {
    s32 idx;
    s32 val;

    idx = func_00505B20();
    val = func_004A0208(idx);
    D_0021F7E8 = 0;
    *(s32 *)((u8 *)D_3098F0 + idx * 0x1F8) = val;
    func_0049B1A0(idx, 6);
    func_00497980(7);
}
