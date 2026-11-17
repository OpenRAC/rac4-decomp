#include "common.h"

extern s32 func_004978C0(s32 i);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern int func_00549CA0(s32 a, int b);
extern s32 func_0054A0C0(s32 item, s32 mode);
extern s32 func_0054A788(s32, s32, s32);
extern u8 D_30B7F8[];

// Check whether the current player's selected item passes three tests for slot arg0 + 1.
s32 func_004C3310(s32 arg0) {
    s32 r = 0;
    s32 idx = func_00505B20();
    u8 *e = D_30B7F8 + idx * 0x74;
    u8 *q = func_00510BE8(idx);
    s32 item = func_004978C0(*(s32 *)(e + 0xC));

    if (e[0x62] == 0) {
        if (func_0054A788(*(s32 *)(q + 0x26E4), item, arg0 + 1) == 0) {
            goto end;
        }
    }
    if (func_00549CA0(*(s32 *)(q + 0x26E4), arg0 + 1) != 0 && func_0054A0C0(item, arg0 + 1) != 0) {
        goto found;
    }
end:
    return r;
found:
    r = 1;
    goto end;
}
