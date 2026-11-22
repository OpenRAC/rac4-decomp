#include "common.h"

extern s32 func_00525190(void *);
extern void func_0054AEA0(void *);

void func_L01_00408008(s32 a0, u8 *p) {
    u8 f;
    if (a0 != 0 && p != 0) {
        f = p[0x266D];
        if (f != 0 && func_00525190(p) != 0) {
            if (*(f32 *)(p + 0x1A20) >= 0.8f) {
                *(s32 *)(p + 0x1848) = *(s32 *)(p + 0x19FC);
            }
        } else if (p[0x266D] == 0) {
            func_0054AEA0(p);
        }
    }
}
