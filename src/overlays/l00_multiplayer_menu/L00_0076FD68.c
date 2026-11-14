#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 func_L00_0076F368(void *);
extern s32 func_L00_0076F770(void *);
extern u8 *D_002233A4;

/* Expires the object's two timed flags once the clock has passed their limits. */
s32 func_L00_0076FD68(void *arg0) {
    u8 *p = arg0;
    u8 *s1 = D_002233A4;
    s32 s2 = 1;

    if (p[0x12] != 0) {
        if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(p + 0x18) >= 0x3A99) {
            *(s32 *)(s1 + 0x10) = 2;
            if (*(s32 *)(s1 + 0x14) == 0) {
                *(s32 *)(s1 + 0x14) = 2;
            }
            p[0x12] = 0;
            func_L00_0076F770(p);
            s2 = 0;
        }
    } else if (p[0x13] != 0 && *(s32 *)(p + 0x14) < (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(p + 0x18)) {
        s2 = func_L00_0076F770(p);
    }
    if (p[0x4] != 0) {
        if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(p + 0xC) >= 0x3A99) {
            *(s32 *)(s1 + 0x10) = 2;
            if (*(s32 *)(s1 + 0x14) == 0) {
                *(s32 *)(s1 + 0x14) = 2;
            }
            p[0x4] = 0;
            s2 = 0;
            func_L00_0076F368(p);
        }
    } else if (p[0x5] != 0 && *(s32 *)(p + 0x8) < (s32)func_0012FEB0(func_0012E370(), 0x24000) - *(s32 *)(p + 0xC)) {
        s2 = func_L00_0076F368(p);
    }
    return s2;
}
