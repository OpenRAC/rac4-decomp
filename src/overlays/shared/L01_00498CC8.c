#include "common.h"

typedef struct Type2 {
    char _p0[0x4];
    s32 f4;
    char _p8[0x60 - 0x8];
    s32 f60;
    char _p64[0x68 - 0x64];
    s32 f68;
} Type2;

typedef struct Type1 {
    char _p0[0x20];
    u8 f20;
    char _p21[0xAC - 0x21];
    Type2 *fAC;
    char _pB0[0xBC - 0xB0];
    s16 fBC;
} Type1;

extern s32 func_L00_005C8CF0(s32);
extern s32 func_L01_00497878(Type1 *arg0);

/* Counts a hit on the object's match slot when the stored values agree with the arguments. */
void func_L01_00498CC8(Type1 *arg0, s32 arg1, s32 arg2) {
    Type2 *p;
    s32 ok;

    if (arg0->fBC == 0x2682) {
        p = arg0->fAC;
        if (arg0->f20 == 0) {
            func_L01_00497878(arg0);
        }
        if (p->f60 != 0) {
            ok = 1;
            if (p->f68 != -1) {
                if (p->f68 != func_L00_005C8CF0(arg2)) {
                    ok = 0;
                }
            }
            if (p->f60 != arg1) {
                ok = 0;
            }
            if (ok) {
                p->f4++;
            }
        }
    }
}
