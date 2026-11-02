#include "common.h"

s32 func_L00_0063CB10();
s32 func_00699138(s32);
s32 func_0069DC48(s32);
s32 func_0069DC90();
s32 func_0069DE78(s32);
extern s32 D_0030F640[];
#define D_3095B0 (D_0030F640[0])

void func_L00_0063CBD0(s32 a0) {
    s32 temp_s0;

    if (D_3095B0 == 0) {
        temp_s0 = func_0069DC90();
        func_0069DC48(4);
        func_00699138(func_L00_0063CB10());
        func_0069DE78(func_L00_0063CB10());
        func_0069DC48(temp_s0);
    }
    D_3095B0 |= 1 << a0;
}
