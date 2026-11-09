/* cflags: -fno-schedule-insns */
#include "common.h"

typedef struct {
    char _p0[0x10];
    f32 f10;
    f32 f14;
    s32 f18;
} Type1;
extern Type1 D_0032FB70;

void func_L01_005E5BC0(s32 arg0, f32 fparg0) {
    D_0032FB70.f10 = 1.0f;
    D_0032FB70.f14 = fparg0;
    D_0032FB70.f18 = arg0;
}
