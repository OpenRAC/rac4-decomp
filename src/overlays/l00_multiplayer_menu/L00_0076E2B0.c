#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_L00_0076E478(void *arg0, s32 arg1);

// Updates a menu entry's state, calls its hook when it is ready, and stores a timer value.
void func_L00_0076E2B0(void *arg0, void *arg1) {
    u8 *s0 = arg0;
    u8 *s1 = arg1;
    s32 t = *(s32 *)(s1 + 0xAC);
    void (*fn)(s32, void *, s32, s32);
    s32 r;

    if (t == 1) {
        s1[0xC5] = 0x31;
    } else if (t == 0) {
        fn = *(void (**)(s32, void *, s32, s32))(s0 + 0xCC);
        if (fn != 0) {
            fn(*(s32 *)(s0 + 4), s1, *(s32 *)(s0 + 0x10), *(s32 *)(s0 + 0xD0));
        }
    } else {
        if (t == -0x3C4) {
            *(s32 *)(s0 + 0x10) = 0x29;
        } else {
            *(s32 *)(s0 + 0x10) = 0x28;
        }
        if (s1[0xC5] != 0) {
            if (*(s32 *)(s0 + 8) != 0) {
                func_L00_0076E478(s0, 6);
            }
        }
    }
    if (*(s32 *)s0 == 0xC) {
        if (s1[0xC5] != 0) {
            fn = *(void (**)(s32, void *, s32, s32))(s0 + 0xCC);
            if (fn != 0) {
                fn(*(s32 *)(s0 + 4), 0, *(s32 *)(s0 + 0x10), *(s32 *)(s0 + 0xD0));
                *(void **)(s0 + 0xCC) = 0;
            }
            func_L00_0076E478(s0, 0);
        }
    }
    r = func_0012FEB0(func_0012E370(), 0x24000);
    *(s32 *)(s0 + 0xC) = r;
}
