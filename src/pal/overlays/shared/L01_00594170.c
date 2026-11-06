/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division */
#include "common.h"
s32 func_L01_00594170(u8 *a0) {
    if (a0 == 0) {
        return 0;
    }
    if (*(u16 *)(a0 + 52) & 0x20) {
        return *(s32 *)(*(u8 **)(a0 + 172) + 32);
    }
    return 0;
}
