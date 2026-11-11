#include "common.h"

extern s32 func_0011D9A8(void *, const char *, ...);
extern u8 D_002217E8[];

// Scan three consecutive eight-byte input slots into matching unsigned-word outputs.
// Preserve the existing 32-bit address-word interface (sibling of func_L00_00767C60).
void func_L00_00767CE0(s32 dest, s32 values) {
    s32 value_ptr = values;
    s32 out = dest;
    u32 count = 0;
    do {
        count += 1;
        func_0011D9A8((void *)out, (const char *)D_002217E8, (u32 *)value_ptr);
        value_ptr += 4;
        out += 8;
    } while (count < 3U);
}
