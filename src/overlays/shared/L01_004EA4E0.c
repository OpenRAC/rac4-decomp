#include "common.h"

extern void func_L00_005F1778(int, void *, int);

// Pick the next non-empty slot of 6 round-robin, advance the cursor, and call func_L00_005F1778 on it.
s32 func_L01_004EA4E0(s32 ignored, u8 *arg1, void *arg2) {
    s32 i;
    s32 *slots = (s32 *)(arg1 + 0x378);
    s32 idx;
    s32 v;
    for (i = 0; i < 6; i++) {
        idx = (i + arg1[0x377]) % 6;
        v = *(s32 *)((u8 *)slots + (idx << 2));
        if (v != 0) {
            arg1[0x377] = (idx + 1) % 6;
            func_L00_005F1778(v, arg2, 0);
            return v;
        }
    }
    return 0;
}
