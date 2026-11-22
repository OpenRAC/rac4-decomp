#include "common.h"
typedef int u128 __attribute__((mode(TI)));
typedef struct O { char _pad0[0xA4]; s32 fA4; s32 fA8; } O;
typedef struct P { char _pad0[0xAC]; O *fAC; } P;
extern s32 D_00222B50;
extern void func_0046C978(void *, s32, void *);
extern s32 func_004534D0(void *);
extern s32 func_0047ED10(s32);
extern void func_L01_0046FC98(f32, void *, void *, s32);
extern void func_L01_0046FEE0(void *, u128);
void func_L01_00470028(P *p) {
    u128 buf;
    O *o = p->fAC;
    if (o->fA4 != 0) {
        s32 c;
        func_0046C978(p, 1, &buf);
        func_004534D0(&o->fA8);
        if (o->fA8 < 15) {
            if (o->fA4 == 2) {
                c = func_0047ED10(0x80);
            } else {
                c = 0x803040;
            }
            func_L01_0046FC98(0.35f, &buf, &D_00222B50, c);
        }
        if ((u32)(o->fA8 - 1) < 0x3B) {
            func_L01_0046FEE0(p, buf);
        }
    }
}
