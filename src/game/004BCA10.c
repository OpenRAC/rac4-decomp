#include "common.h"

extern s32 func_00505B20(void);
extern s32 D_0021F198;
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

s32 func_004BCA10(void) {
    s32 result;
    s32 searching;
    u8 *base;
    u8 *p;
    s32 i;
    u8 *e;
    s32 target;

    base = (u8 *)(func_00505B20() * 0x534 + (s32)D_30A6F0);
    result = -1;
    searching = 1;
    target = D_0021F198;
    if (target != -1) {
        p = base + 0x4C8;
        for (i = 0; i < *(s32 *)(p + 0x50); i++) {
            if (searching) {
                e = *(u8 **)(get_entry(base + 0x4C8, i) + 8);
                if (*(s32 *)(e + 8) != 1 && *(s32 *)(e + 4) == target) {
                    result = i;
                    searching = 0;
                }
            }
        }
    }
    return result;
}
