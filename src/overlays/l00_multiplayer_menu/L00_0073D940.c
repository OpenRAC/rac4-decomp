#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern void func_L00_00709AC8();
extern s32 D_00223404;
extern s8 D_004BD188[];

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0xF];
    char f1B[0x185];
} Type1;

// Formats a message into a stack record and submits it.
void func_L00_0073D940(s32 arg0) {
    Type1 rec;

    rec.f0 = D_00223404;
    rec.f4 = 1;
    func_0011D920(rec.f1B, D_004BD188);
    rec.f8 = arg0;
    func_L00_00709AC8(&rec);
}
