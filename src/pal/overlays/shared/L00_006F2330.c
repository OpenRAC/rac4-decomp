#include "common.h"

s32 func_L00_006F2330(void *arg0) {
    if ((((*(u8 *)((s8 *)(arg0) + (0x2F2F))) != 0xFF) && ((*(u8 *)((s8 *)(arg0) + (0x2F2D))) == 0x17)) || (((*(u32 *)((s8 *)(arg0) + (0x3A80))) - 0x17U) < 3U)) {
        return 1;
    }
    return 0;
}
