#include "common.h"

typedef struct Type2 Type2;
typedef struct Type1 Type1;
struct Type2 {
    char _p0[0x3C];
    void (*f3C)(Type1 *, s32, s32, s32, s32);
};
struct Type1 {
    char _p0[0x14];
    Type2 *f14;
    char _p18[0x2D8];
    s32 f2F0;
    char _p2F4[0x300];
    s16 f5F4;
    char _p5F6[0x14EA];
    s32 f1AE0;
    char _p1AE4[0x141C];
    s32 f2F00;
    char _p2F04[0xC];
    s32 f2F10;
};

s32 func_0048F878(s32, s32, void *, s32);
s32 func_004908D0(s32, s32);
s32 func_00515718(Type1 *);
void func_00521078(Type1 *);

s32 func_00521720(Type1 *p, s32 arg1, s32 arg2)
{
    s32 pad[8];
    s32 buf[4];
    s32 v;

    if (func_0048F878(func_004908D0(0x40, p->f2F10), arg1, buf, p->f2F00) == 0) {
        return 0;
    }
    func_00521078(p);
    func_004908D0(8, p->f2F10);
    if (p->f5F4 == 0) {
        v = p->f1AE0;
        if (v == 1 && func_0048F878(0x28, 2, 0, p->f2F00) != 0 && func_00515718(p) != v) {
            func_00515718(p);
        }
    }
    if (arg2 == 0) {
        if (p->f2F0 != 0) {
            p->f14->f3C(p, 7, 1, 0, 1);
            return 1;
        }
        return 0;
    }
    return 0;
}
