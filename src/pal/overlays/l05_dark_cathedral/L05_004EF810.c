/* cflags:  */
#include "common.h"

extern s32 func_L01_004DB0A0(void *);
extern s32 func_L01_00589E70(void *);
extern s32 func_L01_0058A000(void *);
extern s32 func_00474368(void *, s32, s32);

void func_L05_004EF810(u8 *arg0) {
    if (func_L01_0058A000(arg0) == 0) {
        if (arg0[0x20] == 0) {
            func_L01_004DB0A0(arg0);
        }
        if (arg0[0x20] == 1 && func_L01_00589E70(arg0) != 0) {
            func_00474368(arg0, 2, -1);
        }
    }
}
