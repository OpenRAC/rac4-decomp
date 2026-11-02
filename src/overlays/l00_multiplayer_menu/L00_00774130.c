#include "common.h"

extern s32 func_L00_007672D8(s32);
extern void func_L00_00767340(s32, s32, s32, s32);

// Once (flag +0x74 clear): take an amount from the +0x2C pool into +0x30 and
// pass it with param to func_L00_00767340, then raise the flag.
void func_L00_00774130(void *object, s32 param) {
    s32 value;
    if (*(u8 *)((u8 *)object + 0x74) != 0) return;
    value = func_L00_007672D8(*(s32 *)((u8 *)object + 0x30));
    func_L00_00767340(*(s32 *)((u8 *)object + 0x3C), *(s32 *)((u8 *)object + 0x30), value, param);
    *(u8 *)((u8 *)object + 0x74) = 1;
    *(s32 *)((u8 *)object + 0x2C) -= value;
    *(s32 *)((u8 *)object + 0x30) += value;
}
