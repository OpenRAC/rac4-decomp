#include "common.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u16 count;
    u16 f2;
    u32 best;
    u32 flags;
} ProgressEntry;

extern s32 func_00453D20(s16 *arg0);
extern void func_0051C078(u8 *arg0);
extern s32 func_00526388(u8 *arg0);
extern s32 D_0021DE98;
extern ProgressEntry D_001F7750[];
extern u32 D_0021DAF0;

void func_0051C158(u8 *arg0) {
    f32 f;
    s32 n;
    s16 v;
    ProgressEntry *p;
    ProgressEntry *base;

    *(f32 *)(arg0 + 0x5F8) = *(f32 *)(arg0 + 0x17A0);
    *(u128 *)(arg0 + 0x5E0) = *(u128 *)(arg0 + 0x1790);
    func_00453D20((s16 *)(arg0 + 0x608));
    func_00453D20((s16 *)(arg0 + 0x60A));
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
    if (func_00526388(arg0) != 0) {
        base = D_001F7750;
        p = &base[3];
        if (base[3].count < 0xFFFF) {
            base[3].count++;
        }
        if (D_0021DAF0 > p->best) {
            p->best = D_0021DAF0;
        }
        p->flags = p->flags | (1 << ((D_0021DE98 - 1) % 20)) | 0x80000000;
    }
    func_0051C078(arg0);
    *(s32 *)(arg0 + 0x17A8) = 0;
    *(s32 *)(arg0 + 0x17A4) = 0;
}
