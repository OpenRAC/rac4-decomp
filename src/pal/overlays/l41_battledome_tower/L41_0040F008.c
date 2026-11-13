#include "common.h"
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } Type1;
extern Type1 D_00375B50[][4];
s32 func_L41_0040F008(s32 arg0, s32 arg1) {
    return D_00375B50[arg0][arg1].f4 == 0;
}
