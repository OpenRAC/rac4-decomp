#include "common.h"

extern void func_005CD220(s32 arg0);
extern s32 D_001DFCA0[];
#define D_1DFCA0 (D_001DFCA0[0])

// Call func_005CD220 with arg1 unless arg1 already equals D_1DFCA0.
void func_L00_0065DC08(s32 arg0, s32 arg1) {
    if (D_1DFCA0 != arg1) {
        func_005CD220(arg1);
    }
}
