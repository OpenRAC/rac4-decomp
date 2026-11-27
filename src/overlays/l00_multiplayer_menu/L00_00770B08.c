#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 func_L00_00770BE8(u8 *arg0);

s32 func_L00_00770B08(u8 *arg0) {
    s32 s1 = 1;
    s32 v1;

    if (arg0[0x20] == 0) {
        if (arg0[0x14] != 0) {
            s32 t = (s32)func_0012FEB0(func_0012E370(), 0x24000);
            v1 = 1;
            if (*(s32 *)(arg0 + 0x24) >= 0) {
                v1 = ((t - *(s32 *)(arg0 + 0x24)) < *(s32 *)(arg0 + 0x18)) ? 0 : s1;
            }
            if (v1 != 0) {
                s1 = func_L00_00770BE8(arg0);
            }
        }
    } else {
        s32 t = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        if ((t - *(s32 *)(arg0 + 0x24)) >= 0x3A99) {
            arg0[0x20] = 0;
            s1 = 0;
            func_L00_00770BE8(arg0);
        }
    }
    return s1;
}
