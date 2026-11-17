#include "common.h"

typedef struct {
    u8 f0[10][16];
    u8 fA0[10][8];
    u8 fF0[10];
    u8 fFA[10];
    u8 f104[10];
    u8 f10E[10];
} Type1;

extern Type1 *D_0021DFE8;
extern u8 D_001723B0[];
extern u8 *D_002233A4;
extern void func_L00_0075C0B0(u8 *obj, s32 a1, s32 a2);
extern s32 func_L00_0075C840(s32 arg0, s32 arg1, s32 *arg2);
extern void func_L00_007700A8(u8 *, s32, u8 *, s32, s32, s32, u8 *);

// Applies a slot change: clears its flag and notifies, or forwards a mode to func_L00_0075C0B0.
void func_L00_0075C8F8(u8 *arg0, s32 arg1) {
    s32 r;
    u8 *x;

    if (func_L00_0075C840((s32)arg0, arg1, &r) != 0) {
        if (D_001723B0[0] != 0) {
            x = *(u8 **)(D_002233A4 + 0x48);
            D_0021DFE8->f10E[arg1] = 0;
            func_L00_007700A8(x, arg1, D_0021DFE8->f0[arg1], D_0021DFE8->fF0[arg1], D_0021DFE8->fFA[arg1],
                              D_0021DFE8->f10E[arg1], D_0021DFE8->fA0[arg1]);
        } else if (r == 0) {
            func_L00_0075C0B0(arg0, 1, arg1);
        } else {
            func_L00_0075C0B0(arg0, 2, arg1);
        }
    }
}
