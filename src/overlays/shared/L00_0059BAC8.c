#include "common.h"

extern u8 D_0022CAE0[];
extern s32 func_L00_00568FB0(void *, s32);
extern void func_L00_005DD4A0(void *);

// Per-entry slot update: when the flag at 0x86 is zero, fill the 0xC4 slot once; otherwise release it and clear the slot.
void func_L00_0059BAC8(s32 arg0, void *arg1) {
    s32 off = arg0 * 0x470;
    u8 *entry = D_0022CAE0 + off;
    s32 temp;
    if (*(s16 *)((u8 *)arg1 + 0x86) == 0) {
        if (*(s32 *)(entry + 0xC4) == 0) {
            *(s32 *)(entry + 0xC4) = func_L00_00568FB0(D_0022CAE0 + off - 0x60, arg0);
        }
    } else {
        temp = *(s32 *)(entry + 0xC4);
        if (temp != 0) {
            func_L00_005DD4A0((void *)temp);
            *(s32 *)(entry + 0xC4) = 0;
        }
    }
}
