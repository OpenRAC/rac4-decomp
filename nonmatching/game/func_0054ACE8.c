/* Not matching yet: BYTES 17/224 (tools/try_func.py func_0054ACE8 --diff). Not part of the build. */
#include "common.h"

extern s32 func_0054AB98(s32 arg0, s32 *arg1);
s32 func_0054ADC8(s32 *arg0);
extern s32 D_00171B4C[];
extern unsigned int D_00171C08[];
extern u8 D_1F87F0[];

s32 func_0054ACE8(s32 *arg0) {
    s32 buf;
    s32 id;
    s32 r;
    s32 ret;

    if (func_0054ADC8(arg0) == 0) {
        return 0;
    }
    ret = 0;
    if (arg0[0] > D_00171B4C[0]) {
        return ret;
    }
    if ((u32)(arg0[4] + 1) >= 2) {
        r = func_0054AB98(arg0[4], &buf);
        if (D_1F87F0[r * 12 + ((buf - 1) % 20) * 0x304 + 9] == 0) {
            return 0;
        }
    }
    id = arg0[5];
    if (id == -1 || (D_00171C08[(u32)id >> 5] & (1 << (id & 31)))) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}
