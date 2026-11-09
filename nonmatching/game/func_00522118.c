/* Not matching yet: BYTES 22/616 (tools/try_func.py func_00522118 --diff). Not part of the build. */
#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x3C];
    s32 (*f3C)(void *, s32, s32, s32, s32);
};

extern u128 func_004FE080(u128, f32);
extern s32 func_00512650(void *, s32);
extern void func_0051B168(void *, s32, f32);
extern void func_00522E38(void *, s32, s32, s32, f32);
extern f32 D_0021DDF4;
extern s32 D_00220BC4;

void func_00522118(u8 *p)
{
    f32 f;
    s32 n;

    *(s32 *)(p + 0x2DDC) = 0;
    func_0051B168(p, 0, 1.0f);
    if (*(f32 *)(p + 0x2E08) > 0.3f && *(s16 *)(p + 0x3BA) == 0) {
        if (p[0x432] != 0 || p[0x2661] != 0) {
            (*(Type2 **)(p + 0x14))->f3C(p, 2, 1, 0, 1);
            return;
        }
        if ((*(Type2 **)(p + 0x14))->f3C(p, 2, 0, 0, 1) != 0) {
            *(s32 *)(p + 0x25D0) = 1;
            n = 8;
            if (p[0x1D0C] >= 6) {
                n = 14;
            }
            f = n;
            func_00522E38(p, 7, D_00220BC4, 0, f);
            if (*(s32 *)(p + 0x2318) == 2) {
                func_00522E38(p, 0x56, D_00220BC4, 0, f);
            }
            p[0x1C8E] = 1;
        }
        return;
    }
    if ((D_0021DDF4 * 3.0f * *(f32 *)(p + 0x25C4) < *(f32 *)(p + 0x1B8) && p[0x1D0C] >= 4) || *(s32 *)(p + 0x25CC) == 0x10) {
        if ((*(Type2 **)(p + 0x14))->f3C(p, 3, 0, 0, 1) != 0) {
            func_00522E38(p, 9, 0, 0, -1.0f);
            *(u128 *)(p + 0x1A0) = func_004FE080(*(u128 *)(p + 0x1A0), D_0021DDF4 * 5.0f * *(f32 *)(p + 0x25C4));
        }
    } else if (p[0x1D0C] >= 13 || (*(s32 *)(p + 0x648) & 2)) {
        *(s32 *)(p + 0x1B04) = 0;
        if ((*(Type2 **)(p + 0x14))->f3C(p, 0, 0, 0, 1) != 0) {
            func_00522E38(p, func_00512650(p, 0), 0, 0, -2.0f);
        }
    }
}
