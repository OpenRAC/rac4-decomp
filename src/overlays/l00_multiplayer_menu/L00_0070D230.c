#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_L00_0070D1A0(void);
s32 D_00220B10 = 0;

// If the stored deadline is set and has passed, run the expiry handler and clear it.
void func_L00_0070D230(void) {
    s32 now = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    if (D_00220B10 != -1 && D_00220B10 < now) {
        func_L00_0070D1A0();
        D_00220B10 = -1;
    }
}
