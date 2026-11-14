#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern void func_L00_00709AC8();
extern char D_00220B30[];
extern s32 D_003B1738[];
extern s32 D_003F41DC[];
s32 D_00220B0C = 0;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char fC[0xF];
    char f1B[0x185];
} Type1;

// Formats a message into a stack record and submits it.
void func_L00_0070F9E0(void) {
    Type1 rec;

    rec.f0 = D_003F41DC[0];
    rec.f4 = 1;
    rec.f8 = D_003B1738[0];
    func_0011D920(rec.f1B, D_00220B30, D_00220B0C);
    func_L00_00709AC8(&rec);
}
