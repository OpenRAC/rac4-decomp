#include "common.h"

extern s32 func_15DB80(s32, s32);
extern s32 func_L00_0076CB48(s32, s32, s32);
extern s32 func_L00_0076CB00(s32);

// On the first call, transfer an amount from +0x2C to +0x30, store the
// result at +0x40, and raise the flag at +0x75.
s32 func_L00_00773DA0(void *object, s32 param) {
    s32 amount;
    if (*((u8 *)object + 0x75) == 0) {
        amount = func_L00_0076CB00(*(s32 *)((u8 *)object + 0x30));
        *(s32 *)((u8 *)object + 0x40) = func_L00_0076CB48(func_15DB80(0x10, *(s32 *)((u8 *)object + 0x30)), amount, param);
        *(s32 *)((u8 *)object + 0x2C) -= amount;
        *(s32 *)((u8 *)object + 0x30) += amount;
        *((u8 *)object + 0x75) = 1;
    }
    return *(s32 *)((u8 *)object + 0x40);
}
