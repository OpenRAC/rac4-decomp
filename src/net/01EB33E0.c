/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; u8 *f10; } Ent_14;
extern s32 func_01EA90F0(s32);
extern Ent_14 *func_01EB3028(s32, s32);
extern s32 func_01EA8F98(u8 *);
extern void *func_0011A370(void *, void *, s32);
extern void *func_0011A518(void *, s32, s32);
s32 func_01EB33E0(s32 a, s32 b, u8 *dst) {
    s32 x;
    Ent_14 *e;
    x = func_01EA90F0(a);
    if (x != 0) {
        e = func_01EB3028(x, b);
        if (e != 0 && func_01EA8F98(e->f10) == 0) {
            func_0011A370(dst, e->f10, 0x40);
            return 0;
        }
    }
    if (dst != 0) {
        func_0011A518(dst, 0, 0x40);
    }
    return -1;
}
