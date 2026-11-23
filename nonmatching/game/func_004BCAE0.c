/* Not matching yet: SIZE ours 180 / retail 176 (tools/try_func.py func_004BCAE0 --diff). Not part of the build. */
#include "common.h"

extern s32 func_00505B20(void);
extern u8 D_30A6F0[];

static inline u8 *get_entry(u8 *p, s32 i) {
    if (i < 0) {
        i = *(s32 *)(p + 0x54);
        if (i < 0) {
            return 0;
        }
    }
    return *(u8 **)(p + 0x34) + i * 0x18;
}

s32 func_004BCAE0(void) {
    s32 result;
    u8 *base;
    u8 *p;
    s32 i;
    u8 *e;

    base = (u8 *)(func_00505B20() * 0x534 + (s32)D_30A6F0);
    result = -1;
    if (*(s32 *)(base + 0x518) > 0) {
        i = 0;
        do {
            p = base + 0x4C8;
            if (result == -1) {
                e = *(u8 **)(get_entry(p, i) + 8);
                if (*(s32 *)(e + 8) != 1) {
                    result = (*(u8 *)(e + 1) == 0) ? i : result;
                }
            }
            i++;
        } while (i < *(s32 *)(p + 0x50));
    }
    return result;
}
