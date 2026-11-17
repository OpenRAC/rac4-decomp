#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
s32 D_00220B10 = 0;

/* Stores func_0012FEB0(func_0012E370(), 0x24000) + 1000 into a global. */
void func_L00_0070D1F0(void) {
    D_00220B10 = (s32)func_0012FEB0(func_0012E370(), 0x24000) + 0x3E8;
}
