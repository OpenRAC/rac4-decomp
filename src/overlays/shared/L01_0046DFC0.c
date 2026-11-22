#include "common.h"
typedef struct H H;
typedef struct VT { char _p0[0x4C]; s32 (*f4C)(H *); } VT;
struct H { char _p0[0x14]; VT *f14; char _p18[0x25CC - 0x18]; s32 f25CC; char _p25D0[0x266D - 0x25D0]; u8 f266D; char _p266E[0x2E20 - 0x266E]; f32 f2E20; };
typedef struct S { char _p0[0x30]; s32 f30; char _p34[0x40 - 0x34]; H *f40; char _p44[0x4E - 0x44]; u8 f4E; } S;
typedef struct O { char _p0[0x20]; u8 f20; char _p21[0xAC - 0x21]; S *fAC; } O;
extern s32 D_0021DD9C;
extern void *func_00510C30(H *);
extern s32 func_L00_00658420(s32);
extern void func_004E8DD0(f32, S *, void *, s32, s32, void *);
void func_L01_0046DFC0(O *o) {
    S *s;
    H *h;
    if (o != NULL && o->f20 != 0xFE && o->f20 != 0xFD) {
        s = o->fAC;
        if (s != NULL) {
            h = s->f40;
            if (h != NULL && h->f266D != 0 && h->f14->f4C(h) == D_0021DD9C && s->f30 != 0 && h->f2E20 > 0.0f) {
                s32 k = h->f25CC;
                if (k != 0x17) {
                    if (k != 0x18) {
                        if (k != 0x19) {
                            if (k != 0x1A) {
                                if (func_L00_00658420(h->f14->f4C(h)) == 0 && s->f4E == 0) {
                                    func_004E8DD0(1.0f, s, (char *)s + 0x10, 0, 1, func_00510C30(h));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
