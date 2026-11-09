/* Not matching yet: BYTES 12/336 (tools/try_func.py func_0051AFD8 --diff). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u16 f0;
    u16 f2;
    u32 f4;
    u32 f8;
} Type1;

extern s32 func_00453508(s16 *arg0);
extern void func_0051AEF8(u8 *arg0);
extern s32 func_00525190(u8 *arg0);
extern s32 D_0021DE10;
extern Type1 D_001F76C8[];
extern u32 D_0021DA70;

void func_0051AFD8(u8 *arg0) {
    f32 f;
    s32 n;
    s16 v;
    Type1 *p;
    Type1 *base;

    *(f32 *)(arg0 + 0x5F8) = *(f32 *)(arg0 + 0x17A0);
    *(u128 *)(arg0 + 0x5E0) = *(u128 *)(arg0 + 0x1790);
    func_00453508((s16 *)(arg0 + 0x608));
    func_00453508((s16 *)(arg0 + 0x60A));
    n = *(u8 *)(arg0 + 0x5F7);
    f = 1.0f;
    if (n == 0) {
        *(s16 *)(arg0 + 0x60A) = 3;
        if (*(s16 *)(arg0 + 0x608) != 0) {
            f = n / 3;
        }
    } else if (n == 1) {
        v = *(s16 *)(arg0 + 0x60A);
        *(s16 *)(arg0 + 0x608) = 3;
        if (v != 0) {
            f = (3 - v) / 3;
        }
    }
    *(f32 *)(arg0 + 0x1784) = *(f32 *)(arg0 + 0x1784) * f;
    if (func_00525190(arg0) != 0) {
        base = D_001F76C8;
        p = &base[3];
        if (base[3].f0 < 0xFFFF) {
            base[3].f0++;
        }
        if (D_0021DA70 > p->f4) {
            p->f4 = D_0021DA70;
        }
        p->f8 = p->f8 | (1 << ((D_0021DE10 - 1) % 20)) | 0x80000000;
    }
    func_0051AEF8(arg0);
    *(s32 *)(arg0 + 0x17A8) = 0;
    *(s32 *)(arg0 + 0x17A4) = 0;
}
