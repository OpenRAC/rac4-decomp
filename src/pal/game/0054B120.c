#include "common.h"

u32 func_0054B120(void *p,s32 idx) {
    s32 j=idx-1;
    if((u32)j >= 8) return 0;
    return *((u8*)p+j+0x21);
}
