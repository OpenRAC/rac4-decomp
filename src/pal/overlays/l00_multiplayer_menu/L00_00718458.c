#include "common.h"

extern void func_0011D920(void *, void *, s32);
extern s32 func_L00_006A0428(s32, s32, s32);
extern s32 func_L00_006A0AF8(s32, u8 *);
extern s32 func_L00_006A0BE8(s32, u32);
extern s32 func_0045E850(s32);
extern s32 func_L00_005E8CF8(s32, s32, s32, s32, s32, s32);
extern char D_00220D28[];

void func_L00_00718458(u8 *item) {
    s32 color;
    s32 type;
    s32 count;
    if (*(s32 *)(item + 4) == 0) return;
    if (*(u8 **)(item + 0x14) == 0 && *(u8 **)(item + 0x5C) == 0) return;
    if (*(s32 *)(item + 4) == 1) {
        if (*(u8 **)(item + 0x14) != 0) func_L00_006A0428((s32)*(u8 **)(item + 0x14), 1, 0);
        if (*(u8 **)(item + 0x5C) != 0) func_L00_006A0428((s32)*(u8 **)(item + 0x5C), 1, 0);
        return;
    }
    if (*(u8 **)(item + 0x14) != 0) func_L00_006A0428((s32)*(u8 **)(item + 0x14), 1, 1);
    if (*(u8 **)(item + 0x5C) != 0) func_L00_006A0428((s32)*(u8 **)(item + 0x5C), 1, 1);
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
    count = *(s32 *)(item + 0x60);
    if (count == 0 && *(s32 *)(item + 0xA0) >= 0) func_0011D920(item + 0x75, (void *)func_0045E850(*(s32 *)(item + 0xA0)), *(s32 *)(item + 0x60));
    else if (count == 1 && *(s32 *)(item + 0xA4) >= 0) func_0011D920(item + 0x75, (void *)func_0045E850(*(s32 *)(item + 0xA4)), *(s32 *)(item + 0x60));
    else if (count >= 2 && *(s32 *)(item + 0xA8) >= 0) func_0011D920(item + 0x75, (void *)func_0045E850(*(s32 *)(item + 0xA8)), *(s32 *)(item + 0x60));
    else func_0011D920(item + 0x75, D_00220D28, *(s32 *)(item + 0x60));
    func_L00_006A0AF8((s32)*(u8 **)(item + 0x5C), item + 0x75);
    count = *(s32 *)(item + 0x60);
    *(s32 *)(item + 0x64) = count;
}
