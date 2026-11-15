/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division */
#include "common.h"

s32 func_L00_00757F00(void *object, u32 n) {
    if (n < 4) {
        return 0x1000;
    }
    if (n - 4 < 4) {
        return 0x4000;
    }
    return (n - 8 >= 4) ? 0x2000 : 0x8000;
}
