#include "common.h"

typedef struct {
    char f0[10][16];
    char fA0[10][8];
    u8 fF0[10];
    u8 fFA[10];
    u8 f104[10];
    u8 f10E[10];
} Type1;

extern Type1 *D_0021DFE8;
extern s32 D_0021DBD8;
extern u8 D_172160[];
extern char *func_0011AFC8(char *, char *, s32);
extern u8 func_00161320(void);
extern s32 func_01E9E270(s32 kind, void *obj, s32 c, s32 e, s32 f, s32 g);

/* Writes the name and record into the table at index arg1, or stages them on the stack when func_00161320 is 0. */
s32 func_L00_007700A8(s32 arg0, s32 arg1, char *arg2, s32 arg3, s32 arg4, s32 arg5, char *arg6) {
    u8 frame[0x20];
    u8 *tbl;

    if (func_00161320() != 0) {
        func_0011AFC8(D_0021DFE8->f0[arg1], arg2, 16);
        D_0021DFE8->f0[arg1][15] = 0;
        D_0021DFE8->fA0[arg1][0] = 0;
        if (arg6 != NULL) {
            func_0011AFC8(D_0021DFE8->fA0[arg1], arg6, 4);
            D_0021DFE8->fA0[arg1][4] = 0;
        }
        D_0021DFE8->fFA[arg1] = arg4;
        D_0021DFE8->fF0[arg1] = arg3;
        D_0021DFE8->f10E[arg1] = arg5;
    } else {
        frame[6] = arg5;
        *(s32 *)frame = arg1;
        frame[5] = arg3;
        frame[4] = arg4;
        func_0011AFC8(frame + 7, arg2, 16);
        frame[0x16] = 0;
        func_0011AFC8(frame + 0x17, arg6, 4);
        frame[0x1B] = 0;
        tbl = D_172160;
        if (*(s32 *)(tbl + 0x258) == 0) {
            func_01E9E270(tbl[0x7F8] | 0x50, *(void **)(tbl + 8), *(s32 *)(tbl + 0x254), D_0021DBD8, 0x20, (s32)frame);
        }
    }
    return 1;
}
