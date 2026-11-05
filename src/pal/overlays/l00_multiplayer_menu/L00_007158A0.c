#include "common.h"

extern void func_L00_006A0428(void *, s32, s32);
extern s32 func_L00_006A0AF8(s32, u8 *);
extern s32 func_L00_006A0BE8(s32, u32);
extern s32 func_L00_005E8CF8(s32, s32, s32, s32, s32, s32);
extern char D_00220CD0[];

// Update the two sub-objects at +0x14 and +0x5C for the mode word at +4: mode 0
// does nothing, mode 1 only runs func_L00_006A0428 on them, other modes also set a
// color from the mode (3-6) and a position (+0x18, and +0x64 indexed by +0x14A8
// or D_00220CD0 when the index is negative).
void func_L00_007158A0(u8 *item) {
    s32 color;
    s32 type;
    s32 index;
    if (*(s32 *)(item + 4) == 0) return;
    if (*(u8 **)(item + 0x14) == 0 && *(u8 **)(item + 0x5C) == 0) return;
    if (*(s32 *)(item + 4) == 1) {
        if (*(u8 **)(item + 0x14) != 0) func_L00_006A0428(*(u8 **)(item + 0x14), 1, 0);
        if (*(u8 **)(item + 0x5C) != 0) func_L00_006A0428(*(u8 **)(item + 0x5C), 1, 0);
        return;
    }
    if (*(u8 **)(item + 0x14) != 0) func_L00_006A0428(*(u8 **)(item + 0x14), 1, 1);
    if (*(u8 **)(item + 0x5C) != 0) func_L00_006A0428(*(u8 **)(item + 0x5C), 1, 1);
    type = *(s32 *)(item + 4);
    if (type == 3) color = 0x80808080;
    else if (type == 4) color = 0x80D6CBBE;
    else if (type == 5) color = func_L00_005E8CF8(0x80D6CBBE, 0x66A6BEFA, 0x25, 1, 0, 1);
    else if (type == 6) color = 0x66A6BEFA;
    else color = 0x80D6CBBE;
    if (*(u8 **)(item + 0x14) != 0) {
        func_L00_006A0BE8((s32)*(u8 **)(item + 0x14), color);
        func_L00_006A0AF8((s32)*(u8 **)(item + 0x14), item + 0x18);
    }
    if (*(u8 **)(item + 0x5C) == 0) return;
    func_L00_006A0BE8((s32)*(u8 **)(item + 0x5C), color);
    index = *(s32 *)(item + 0x14A8);
    if (index >= 0) func_L00_006A0AF8((s32)*(u8 **)(item + 0x5C), item + 0x64 + index * 0x50);
    else func_L00_006A0AF8((s32)*(u8 **)(item + 0x5C), (u8 *)D_00220CD0);
}
