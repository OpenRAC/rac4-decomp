#include "common.h"

s32 func_L00_00531A40(void *p) {
    extern void D_00531A58(void);
    *(u32*)((u8*)p + 8) = (u32)&D_00531A58;
    return 0;
}
