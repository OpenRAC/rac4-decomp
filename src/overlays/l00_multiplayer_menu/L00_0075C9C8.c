#include "common.h"

typedef struct {
    u8 f0[10][16];
    u8 fA0[10][8];
    u8 fF0[10];
    u8 fFA[10];
    u8 f104[10];
    u8 f10E[10];
} Type1;

extern s32 func_L00_0075C840(s32 arg0, s32 arg1, s32 *arg2);
extern void func_L00_007700A8(u8 *, s32, u8 *, s32, s32, s32, u8 *);
extern u8 *D_002233A4;
extern Type1 *D_0021DFE8;

/* when the helper succeeds, mark entry arg1 of the table with state 6 and report it to func_L00_007700A8 */
void func_L00_0075C9C8(s32 arg0, s32 arg1) {
    s32 buf;
    u8 *first;
    Type1 *tbl;

    if (func_L00_0075C840(arg0, arg1, &buf) != 0) {
        first = *(u8 **)(D_002233A4 + 0x48);
        D_0021DFE8->f10E[arg1] = 6;
        tbl = D_0021DFE8;
        func_L00_007700A8(first, arg1, tbl->f0[arg1], tbl->fF0[arg1], tbl->fFA[arg1], tbl->f10E[arg1],
                          tbl->fA0[arg1]);
    }
}
