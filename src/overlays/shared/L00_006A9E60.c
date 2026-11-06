#include "common.h"

extern s32 D_0021DE10;

/* 1 when D_0021DE10 is in 0x15..0x23 or in 0x3D..0x4B. */
s32 func_L00_006A9E60(void) {
    s32 v = D_0021DE10;
    if ((u32)(v - 0x15) < 0xF) {
        return 1;
    }
    return (u32)(v - 0x3D) < 0xF;
}
