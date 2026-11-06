#include "common.h"

extern u8 *func_L00_005F2FB8(void);

s32 func_L01_005A5850(void) {
    return *(u8 *)(func_L00_005F2FB8() + 2) != 0;
}
