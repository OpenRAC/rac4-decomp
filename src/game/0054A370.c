#include "common.h"

void func_0054A608(char *, s32, s32);
s32 func_00549BD8(char *, s32);
s32 func_0054A370(char *p, s32 idx, s32 val) {
    if ((u32)(val - 1) >= 8) {
        return 0;
    }
    func_0054A608(p, idx, 1);
    if (func_00549BD8(p, val) != 0 || val == 0) {
        ((u8 *)(idx * 0x44 + (s32)p))[0xA3C] = val;
        return 1;
    }
    return 0;
}
