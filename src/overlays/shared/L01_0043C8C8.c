#include "common.h"

extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005F1180(void *, void *);

/* Look up an object by id, link it to the given one and mark it. */
u8 *func_L01_0043C8C8(void *arg0, s32 arg1) {
    u8 *p = func_L00_005DD000(arg1, 0x80);
    if (p) {
        if (*(s32 *)(p + 0x24)) {
            func_L00_005F1180(p, arg0);
        }
        p[0x31] = 1;
        return p;
    }
    return 0;
}
