#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 func_L00_007665A0(void *);

/* Once the value at 0xC lags the func_0012FEB0 timer by 0x3A99, clears the flag at 8 and runs func_L00_007665A0; else 1. */
s32 func_L00_00766520(void *arg0) {
    s32 d;

    if (*(u8 *)arg0 != 0) {
        if (*(u8 *)((u8 *)arg0 + 8) == 0) {
            d = (s32)func_0012FEB0(func_0012E370(), 0x24000);
            if (d - *(s32 *)((u8 *)arg0 + 0xC) >= 0x3A99) {
                *(u8 *)((u8 *)arg0 + 8) = 0;
                return func_L00_007665A0(arg0);
            }
        }
    }
    return 1;
}
