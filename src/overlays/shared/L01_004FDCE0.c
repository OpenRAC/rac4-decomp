#include "common.h"
s32 func_L01_004FDCE0(void *arg0) {
    u8 *a1 = *(u8 **)((u8 *)arg0 + 0xAC);
    u8 *a0 = *(u8 **)(a1 + 0x254);
    if (a0 == 0 || *(s16 *)(a0 + 0xBC) != 0x20EC) return 0;
    if (*(u8 *)(*(u8 **)(a0 + 0xAC) + 0x1F3) != 0) return 0;
    if (*(s16 *)(a1 + 0x76) != 0) return 0;
    return *(u8 *)(a1 + 0x281) != 0;
}
