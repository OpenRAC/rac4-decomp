#include "common.h"

extern s32 func_15DB80(s32, s32);
extern s32 func_L00_00770228(s32, s32, s32);
extern s32 func_L00_00770390(s32);

// On the first call, transfer an amount from +0x2C to +0x30, store the
// result at +0x44, and raise the flag at +0x76.
s32 func_L00_00773D10(void *object, s32 param) {
    s32 amount;
    if (*((u8 *)object + 0x76) == 0) {
        amount = func_L00_00770390(*(s32 *)((u8 *)object + 0x30));
        *(s32 *)((u8 *)object + 0x44) = func_L00_00770228(func_15DB80(0x50, *(s32 *)((u8 *)object + 0x30)), amount, param);
        *(s32 *)((u8 *)object + 0x2C) -= amount;
        *(s32 *)((u8 *)object + 0x30) += amount;
        *((u8 *)object + 0x76) = 1;
    }
    return *(s32 *)((u8 *)object + 0x44);
}
