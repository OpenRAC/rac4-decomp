#include "common.h"
extern u8 D_001723C4_[];
extern s32 func_01E9A858(void *, void *, s32);
extern void func_01E9A7C8(void);
extern void func_01E9A590(s32);
extern void func_0015A050(void);
extern void func_00127A08(s32);
s32 func_00460328(void)
{
    u8 a[0x40];
    u8 b[0x40];
    s32 n = 0x1388;
    if (D_001723C4_[0]) {
        func_01E9A858(b, a, 0x40);
        if (*(s32 *)(b + 0x30) != 5 && *(s32 *)(b + 0x30) != 0) {
            func_01E9A7C8();
        }
        do {
            func_0015A050();
            func_01E9A858(b, a, 0x40);
            func_00127A08(0x1F4);
        } while (*(s32 *)(b + 0x30) != 5 && *(s32 *)(b + 0x30) != 0 && --n != -1);
        func_01E9A590(0);
    }
    return 1;
}
