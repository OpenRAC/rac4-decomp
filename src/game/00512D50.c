#include "common.h"

extern s32 func_004E2288(s32 a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5);

// Calls func_004E2288 with a value derived from the object's state when arg3 is set.
void func_00512D50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p;
    u16 v;
    if (arg3 != 0) {
        v = 0;
        p = *(u8 **)(arg0 + 0x2340);
        if (p != 0) {
            if (*(u16 *)(p + 0x74) == 1) {
                if (*(s16 *)(arg0 + 0x2F8) != 0) v = 1;
            }
        }
        arg4 = (arg4 << 10) / 30;
        func_004E2288(arg1, arg2, v, 0, *(void **)(arg0 + 0x2EF0), arg4);
    }
}
