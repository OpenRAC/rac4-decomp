#include "common.h"
s32 func_L01_0056D698(u8 *p, s32 i) {
    if (i < 0 || i >= *(s32 *)(p + 0x40)) return 0;
    return *(s32 *)(p + (i << 2));
}
