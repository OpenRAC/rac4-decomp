#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

extern Type1 D_0036E150[];

void func_L41_00625C70(s32 arg0, s32 arg1) {
    if (D_0036E150[arg0].f0 <= 0) {
        D_0036E150[arg0].f0 = arg1;
        D_0036E150[arg0].f4 = arg1;
        D_0036E150[arg0].f8 = 0;
        D_0036E150[arg0].fC = 0;
    }
}
