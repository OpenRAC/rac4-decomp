#include "common.h"

extern s32 func_L00_005E60D0(s32, s32);
extern s32 func_L01_0056DB18(s32 arg0);

/* Picks a random matching slot among 16 and stores its index. */
s32 func_L01_004E4F78(u8 *object) {
    u8 *p = *(u8 **)(object + 0xAC);
    s32 mode = *(s16 *)(p + 0x84);
    s32 match = 0;
    s32 total = 0;
    s32 i;
    s32 r;
    u8 *q;
    q = p;
    for (i = 15; i >= 0; i--, q += 8) {
        if (*(s32 *)q == -1) continue;
        total++;
        if (mode == 0 || (mode == -1 && func_L01_0056DB18(*(s32 *)(q + 4)) == 0) ||
            (mode == 1 && func_L01_0056DB18(*(s32 *)(q + 4)) != 0))
            match++;
    }
    if (total == 0) return 0;
    if (match == 0) {
        match = total;
        mode = 0;
    }
    r = func_L00_005E60D0(0, match - 1);
    for (i = 0; i < 16; i++) {
        if (*(s32 *)(p + i * 8) == -1 || (mode == -1 && func_L01_0056DB18(*(s32 *)(p + i * 8 + 4)) != 0) ||
            (mode == 1 && func_L01_0056DB18(*(s32 *)(p + i * 8 + 4)) == 0))
            continue;
        if (r <= 0) {
            *(s16 *)(p + 0x86) = i;
            return 1;
        }
        r--;
    }
    return 0;
}
