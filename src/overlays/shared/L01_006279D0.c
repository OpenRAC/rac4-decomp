#include "common.h"

typedef int u128_4B75B0 __attribute__((mode(TI)));
typedef struct { u8 a; u8 pad[3]; u16 id; u8 pad2[58]; u128_4B75B0 v0; u128_4B75B0 v1; } Ent_004B75B0;
extern u8 *func_L01_00627548(void);
extern void func_L01_00627610(u8 *p, s32 i, s32 v);
extern u32 func_L01_006279D0(s32, s32 *);
extern Ent_004B75B0 D_0034CF60[];

/* from rac3-decomp's func_L04_004BB1A0, constants adapted */
u32 func_L01_006279D0(s32 n, s32 *list) {
    u8 *p;
    s32 i;
    u32 r;
    if (n & 1) {
        r = -1;
    } else {
        p = func_L01_00627548();
        if (p != 0 && n > 0) {
            i = 0;
            do {
                i += 2;
                func_L01_00627610(p, list[0], list[1]);
                list += 2;
            } while (i < n);
        }
        r = -1;
        if (p != 0) {
            r = *(u16 *)(p + 0) | ((u32)(p - (u8 *)D_0034CF60) / 80 << 16);
        }
    }
    return r;
}
