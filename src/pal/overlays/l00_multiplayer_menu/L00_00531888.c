#include "common.h"

s32 func_L00_00531888(void *p) {
    extern void func_L00_005318A0(void);
    *(u32*)((u8*)p + 8) = (u32)func_L00_005318A0;
    return 0;
}
