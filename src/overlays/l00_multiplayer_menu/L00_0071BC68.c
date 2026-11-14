#include "common.h"

extern void func_L00_0071BA48(void *, u32);
extern void func_L00_00623DB8(s32, u32, s32, s32);
s32 D_00220D70 = 0;
s32 D_00220D74 = 0;

// Steps the counter for the byte at 0xA9 down, then if the word at 0x250 is below 4 calls the two helpers, and clears 0x250.
void func_L00_0071BC68(void *arg0) {
    s32 var_s1;

    if (*(u8 *)((u8 *)arg0 + 0xA9) == 1) {
        var_s1 = 4;
        D_00220D74 = D_00220D74 - 1;
    } else {
        var_s1 = 0;
        D_00220D70 = D_00220D70 - 1;
    }
    if (*(u32 *)((u8 *)arg0 + 0x250) < 4) {
        func_L00_0071BA48(arg0, 0xFFFFFFFF);
        func_L00_00623DB8(var_s1, *(u32 *)((u8 *)arg0 + 0x250), *(s32 *)((u8 *)arg0 + 0x240), 0);
    }
    *(s32 *)((u8 *)arg0 + 0x250) = -1;
}
