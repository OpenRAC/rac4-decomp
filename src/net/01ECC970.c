/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA47E8(s32 *table, u32 index);
extern s32 func_01EC90E0(void *, s32);
extern u8 *D_00167F38[];
extern u8 D_1B7258[];

// Walks the net table for an idle entry; when none is busy, sets the flag and calls the callback in D_1B7258.
s32 func_01ECC970(void) {
    u8 *s0;
    s32 i;
    s32 loc[2];
    s32 r;
    s32 fn;
    u8 *b;
    u8 *c;
    u8 *e;

    i = 0;
    b = D_1B7258;
    s0 = *(u8 **)(b + 0x138);
    if (s0 == NULL) {
        return 0;
    }
    if (*(s32 *)(D_00167F38[0] + 0x128) == 0) {
        if (*(u8 **)(s0 + 0x400) == NULL) {
            return 8;
        }
        if ((u32)(*(s32 *)(*(u8 **)(s0 + 0x400) + 0xC) - 4) >= 2U) {
            return 0;
        }
        do {
            if (i != *(s32 *)(s0 + 0x404)) {
                e = (u8 *)func_01EA47E8((s32 *)s0, i);
                if (e != NULL && *(s32 *)(e + 0x20) == 1 && *(s32 *)(e + 0xC) == 0) {
                    return 0;
                }
            }
            i += 1;
        } while (i < 0x100);
        r = func_01EC90E0(s0, -1);
        if (r != 0) {
            return r;
        }
        c = D_1B7258;
        fn = *(s32 *)(c + 0x140);
        *(s32 *)(D_00167F38[0] + 0x128) = 1;
        if (fn != 0) {
            loc[0] = 0;
            loc[1] = *(s32 *)(c + 0x144);
            ((void (*)(s32 *))fn)(loc);
            *(s32 *)(c + 0x140) = 0;
            *(s32 *)(c + 0x144) = 0;
        }
    }
    return 0;
}
