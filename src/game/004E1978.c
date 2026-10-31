#include "common.h"

extern void *func_00453EB0(s16);

// Looks up the entry for arg1 and returns 1 if its flag byte is set and its key matches arg0, else 0.
s32 func_004E1978(s32 arg0, s16 arg1) {
    s32 s1;
    u8 *p;

    s1 = 0;
    p = func_00453EB0(arg1);
    if (p != 0) {
        if (arg0 == *(s32 *)(p + 0x1C)) {
            s1 = p[0x10] != 0;
        }
    }
    return s1;
}
