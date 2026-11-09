/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    u8 pad0[0x18];
    u32 f18;
    u32 f1C;
    u32 f20;
    u8 pad24[4];
} Type2;

typedef struct Type1 {
    u32 f0;
    u32 f4;
    Type2 *f8;
    s32 fC;
} Type1;

extern void func_0011A518(void *, s32, s32);
extern void *func_004FAD00(void *, s32, s32);
extern void *func_L00_004FACD8(unsigned int);

/* grows a pool of 40-byte nodes, rebasing the node links after a realloc */
s32 func_L00_00554050(Type1 *arg0, u32 arg1) {
    Type2 *old;
    Type2 *end;
    Type2 *p;
    u32 i;
    u32 q;
    s32 moved;

    if (arg0->f0 >= arg1) {
        return 0;
    }
    if (arg0->fC & 2) {
    if (arg0->f8 == 0) {
        moved = 0;
        p = func_L00_004FACD8(arg1 * sizeof(Type2));
        func_0011A518(p, 0, arg1 * sizeof(Type2));
    } else {
        moved = 1;
        p = func_004FAD00(arg0->f8, arg1 * sizeof(Type2), arg0->f4 * sizeof(Type2));
        func_0011A518(&p[arg0->f4], 0, (arg1 - arg0->f4) * sizeof(Type2));
    }
    if (p == 0) {
        return 5;
    }
    old = arg0->f8;
    if (old != p && moved) {
        end = &old[arg0->f0];
        for (i = 0; i < arg0->f0; i++) {
            q = p[i].f18;
            if (q >= (u32)old && q <= (u32)end) {
                q = (u32)&p[(Type2 *)q - old];
                p[i].f18 = q;
            }
            q = p[i].f1C;
            if (q >= (u32)old && q <= (u32)end) {
                q = (u32)&p[(Type2 *)q - old];
                p[i].f1C = q;
            }
            q = p[i].f20;
            if (q >= (u32)old && q <= (u32)end) {
                q = (u32)&p[(Type2 *)q - old];
                p[i].f20 = q;
            }
        }
    }
    arg0->f4 = arg1;
    arg0->f8 = p;
    return 0;
    }
    return 6;
}
