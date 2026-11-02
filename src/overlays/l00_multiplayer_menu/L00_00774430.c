#include "common.h"

extern s32 func_L00_007773D0(s32);
extern void func_L00_00777438(s32, s32, s32, s32);

// Once (flag +0x7B clear): take an amount from the +0x2C pool into +0x30 and
// pass it with param to func_L00_00777438, then raise the flag.
void func_L00_00774430(void *object, s32 param) {
    s32 value;
    if (*(u8 *)((u8 *)object + 0x7B) != 0) return;
    value = func_L00_007773D0(*(s32 *)((u8 *)object + 0x30));
    func_L00_00777438(*(s32 *)((u8 *)object + 0x60), *(s32 *)((u8 *)object + 0x30), value, param);
    *(u8 *)((u8 *)object + 0x7B) = 1;
    *(s32 *)((u8 *)object + 0x2C) -= value;
    *(s32 *)((u8 *)object + 0x30) += value;
}
