#include "common.h"
s32 func_L01_004EF1F8(void *arg0) {
    u8 *p=*(u8 **)((u8 *)arg0+0xac);
    u8 *q=*(u8 **)(p+736);
    if (!*(s32 *)(q+0x2b8) && !*(s32 *)(q+0x2bc)) return 0;
    return *(u8 *)(p+853) != 0;
}
