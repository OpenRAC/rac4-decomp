#include "common.h"

typedef struct Type1 {
    char _p0[0x26E4];
    u8 *f26E4;
    char _p26E8[0x828];
    s32 f2F10;
} Type1;

extern void func_00548DF8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00549D20(u8 *, s32, s32, s32);
extern void func_0054A8B0(u8 *);
extern s32 D_0021DF64;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_001D3F90[];

void func_00527050(Type1 *arg0) {
    u8 *p;

    if (D_0021EDD4 == 1) {
        p = D_001D3F90 + arg0->f2F10 * 0x12B0;
        func_0054A8B0(p);
    } else {
        p = D_001D3F90;
        if (p[0] == 0) {
            func_0054A8B0(p);
            func_00548DF8(p, 2, 0, 0, 0);
            func_00548DF8(p, 3, 0, 0, 0);
            func_00548DF8(p, 0xC, 0, 0, 0);
            if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
                func_00548DF8(p, 7, 0, 0, 0);
            }
            func_00548DF8(p, 0xE, 0, 0, 0);
            func_00548DF8(p, 1, 0, 0, 0);
            if (D_0021DF64 >= 3) {
                func_00549D20(p, 4, -1, 0);
            } else {
                func_00549D20(p, 2, -1, 0);
            }
        }
    }
    arg0->f26E4 = p;
}
