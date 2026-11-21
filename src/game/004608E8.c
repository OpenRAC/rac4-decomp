#include "common.h"
typedef struct {
    u8 p0[0xC];
    s32 fC;
    u8 p10[0x2338 - 0x10];
} Item;
extern u8 D_0021EF28[];
extern void func_0011A518(void *, s32, s32);
extern void func_0011D920(void *, void *);
extern s32 func_0012C240(s32);
extern void func_0012C3A8(s32);
extern s32 func_0012C3C8();
extern void func_00460018();
extern void func_00460700(void *, s32);
void func_004608E8(Item *arg0, s32 arg1, void *arg2)
{
    u8 buf[0x80];
    Item *p;
    s32 n;
    void *src;
    s32 a, b, c;
    func_0011A518(buf, 0, 0x80);
    src = arg2;
    if (src == 0) {
        src = D_0021EF28;
    }
    func_0011D920(buf, src);
    if (arg1 > 0) {
    p = arg0;
    n = arg1;
    do {
        s32 v;
        a = func_0012C3C8();
        v = p->fC;
        a -= v;
        func_00460018();
        b = func_0012C240(v + 0x800);
        func_00460018();
        c = func_0012C240(a - 0x800);
        func_00460018();
        if (b != 0) {
            func_0012C3A8(b);
        }
        func_00460018();
        func_00460700(p, c);
        if (c != 0) {
            func_0012C3A8(c);
        }
        func_00460018();
        p++;
    } while (--n != 0);
    }
}
