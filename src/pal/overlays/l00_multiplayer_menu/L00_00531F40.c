#include "common.h"

s32 func_L00_00531F40(void *p) {
    extern void func_L00_00531F58(void);
    *(u32*)((u8*)p + 8) = (u32)&func_L00_00531F58;
    return 0;
}
