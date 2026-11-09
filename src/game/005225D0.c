/* cflags: -ffast-math */
#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;
struct Type2 {
    char _p0[0x3C];
    s32 (*f3C)(Type1 *, s32, s32, s32, s32);
};
struct Type3 {
    char _p0[0x30];
    s16 f30;
};

extern u128 func_004FE080(u128, f32);
extern void func_005168E0(Type1 *arg0);
extern void func_00522E38(void *, s32, s32, s32, f32);
extern Type3 *func_00548D28(s32 arg0, s32 arg1);
extern f32 D_0021DDF4;

s32 func_005225D0(u8 *p)
{
    s32 id;
    s32 v;
    f32 k;
    f32 lim;

    if (p[0x265A] == 0 || p[0x2658] == 0 || p[0x2660] != 0) {
        return 0;
    }
    id = -1;
    if (*(s32 *)(p + 0x2314) == 2) {
        id = *(s32 *)(p + 0x2318);
    }
    if (id == *(s32 *)(p + 0x2DD8)) {
        if (*(s32 *)(p + 0x60C) < 5) {
            return 0;
        }
        v = func_00548D28(id, 0)->f30;
        if ((*(Type2 **)(p + 0x14))->f3C((Type1 *)p, 0, 0, 0, 1) != 0) {
            k = 1.5f;
            *(u128 *)(p + 0x1A0) = func_004FE080(*(u128 *)(p + 0x1A0), D_0021DDF4 * k * *(f32 *)(p + 0x25C4));
            lim = D_0021DDF4 * k * *(f32 *)(p + 0x25C4);
            *(f32 *)(p + 0x1784) = lim < *(f32 *)(p + 0x1784) ? lim : *(f32 *)(p + 0x1784);
            func_00522E38(p, v, 0, 0, 11.0f);
            *(s32 *)(p + 0x2DD4) = v;
            return 1;
        }
    } else {
        func_005168E0((Type1 *)p);
    }
    return 0;
}
