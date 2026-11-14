/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x14]; u8 *f14; u8 *f18; u8 *f1C; } Ent_20;
extern s32 func_01EA90F0(s32);
extern Ent_20 *func_01EB3028(s32, s32);
extern void *func_0011A518(void *, s32, s32);
void func_01EB38E0(s32 a, s32 b) {
    s32 x;
    Ent_20 *e;
    x = func_01EA90F0(a);
    if (x == 0) {
        return;
    }
    e = func_01EB3028(x, b);
    if (e == 0) {
        return;
    }
    if (e->f1C != 0) {
        func_0011A518(e->f1C, 0, 0x40);
    }
    if (e->f14 != 0) {
        func_0011A518(e->f14, 0, 0x10C);
    }
    if (e->f18 == 0) {
        func_0011A518(e->f18, 0, 0x10C);
    }
}
