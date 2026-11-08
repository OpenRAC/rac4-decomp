#include "common.h"

s32 func_00478000(void *);

s32 func_L01_0059B110(void *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if (func_00478000(arg0) != 0) {
        return (*(s16 *)((s8 *)(arg0) + (0xBC))) == 0x1F6;
    }
    return 1;
}
