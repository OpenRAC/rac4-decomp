#include "common.h"
typedef struct Type1 {
    unsigned char f0[6];
    char p6[2];
    int f8, fC;
    unsigned char f10[4];
    int f14, f18;
    char p1C[4];
    unsigned char f20;
    char p21[0x407];
    int f428;
    char p42C[0xB68];
    int fF94;
    char pF98[0xB68];
    int f1B00;
} Type1;

/* Clear the fields initialized by this constructor. */
Type1 *func_L00_0076E5D0(Type1 *arg0) {
    arg0->f0[0] = 0;
    arg0->f0[1] = 0;
    arg0->f0[2] = 0;
    arg0->f0[3] = 0;
    arg0->f0[4] = 0;
    arg0->f0[5] = 0;
    arg0->f8 = 0;
    arg0->fC = 0;
    arg0->f10[0] = 0;
    arg0->f10[1] = 0;
    arg0->f10[2] = 0;
    arg0->f10[3] = 0;
    arg0->f14 = 0;
    arg0->f18 = 0;
    arg0->f20 = 0;
    arg0->f428 = 0;
    arg0->fF94 = 0;
    arg0->f1B00 = 0;
    return arg0;
}
