/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 func_0045CE28();                            /* extern */
s32 func_00474368(s32, s32, s32);               /* extern */
s32 func_L15_004EE020();                        /* extern */
extern s32 D_0021E73C;
extern s32 D_0021E754;
extern s32 D_0021E758;
extern s32 D_0021E834;
s32 D_00222220 = 0;
extern s32 D_00222600;

void func_L15_004EDFA0(s32 arg0) {
    s32 var_4;

    if (arg0 != 0) {
        func_L15_004EE020();
        func_00474368(D_00222220, 7, 4294967295);
    } else {
        var_4 = 1;
        if (D_0021E754 == 0) {
            var_4 = ((D_0021E758 ^ 1) == 0) ? 0x15 : 1;
        }
        D_00222600 = var_4;
        D_0021E73C = 1;
        D_0021E834 = 0;
    }
    func_0045CE28();
}