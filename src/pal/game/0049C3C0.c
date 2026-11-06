#include "common.h"

extern void func_00453E20(void *, s32, s32);
extern u8 D_00307028[];
extern u8 D_00307028__lui[];
extern u8 D_003071D8[];

void func_0049C3C0(void)
{
    s32 i;
    s32 j;
    u8 *p;
    s32 q;
    s32 end;
    s32 one;

    func_00453E20(D_00307028, 0, 0x1B0);
    func_00453E20(D_003071D8, 0, 0x800);
    for (i = 0; i < 4; i++) {
        p = D_003071D8 + (i << 9);
        for (j = 1; j >= 0; j--) {
            p[0xF4] = 1;
            p[0xFC] = 1;
            p += 0x3C;
        }
    }
    one = 1;
    q = (s32)D_00307028__lui;
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
