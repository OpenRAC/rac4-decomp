#include "common.h"

s32 func_L00_00531388(void *p) {
    extern void D_005313A0(void);
    *(u32*)((u8*)p + 8) = (u32)&D_005313A0;
    return 0;
}
