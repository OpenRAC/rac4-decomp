/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4, f8, fC; } G;
extern u8 D_00168BA1;
extern G D_001B23E8;
s32 func_01EABAE8(void);
s32 func_01EABA88(void) {
    if (D_00168BA1 == 0) {
        D_001B23E8.f0 = 0;
        D_001B23E8.f4 = 0;
        D_001B23E8.f8 = 0;
        D_001B23E8.fC = func_01EABAE8();
        D_00168BA1 = 1;
    }
    return 0;
}
