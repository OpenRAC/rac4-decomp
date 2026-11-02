/* cflags: -mno-split-addresses */
#include "common.h"

s32 func_0061FCC8(s32 a0);
void func_00622B10(s32 a0);
void func_L00_00660830(void);
void func_00660B08(s32 a0);
s32 func_0069DC90(void);

void func_L00_00660788(void) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 0;
    temp_s0 = func_0069DC90();
    temp_v0 = func_0061FCC8(6);
    switch (temp_v0) {
    case 2:
        func_00622B10(temp_s0);
        return;
    case 7:
        var_s1 = 1;
        /* fallthrough */
    case 8:
        func_00660B08(var_s1);
        break;
    case 13:
        func_L00_00660830();
        break;
    }
}
