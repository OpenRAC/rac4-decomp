#include "common.h"

extern void func_00453608(void *, s32, s32);
extern u8 D_00306F28[];
extern u8 D_00306F28__lui[];
extern u8 D_003070D8[];

void func_0049B688(void)
{
    s32 i;
    s32 j;
    u8 *p;
    s32 q;
    s32 end;
    s32 one;

    func_00453608(D_00306F28, 0, 0x1B0);
    func_00453608(D_003070D8, 0, 0x800);
    for (i = 0; i < 4; i++) {
        p = D_003070D8 + (i << 9);
        for (j = 1; j >= 0; j--) {
            p[0xF4] = 1;
            p[0xFC] = 1;
            p += 0x3C;
        }
    }
    one = 1;
    q = (s32)D_00306F28__lui;
    end = q + 0x78;
    *(u8 *)(q + 0xF8) = one;
    for (;;) {
        *(u8 *)(q + 0x100) = one;
        q += 0x3C;
        if (q >= end) {
            break;
        }
        *(u8 *)(q + 0xF8) = one;
    }
}
