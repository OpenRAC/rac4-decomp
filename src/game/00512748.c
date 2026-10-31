#include "common.h"

extern s32 D_0021DFF0;
extern s32 D_0021EDD4;

// Returns a 4-bit field of the object at 0x2EF0 when the global state is 1 and a flag is set; otherwise calls the function at 0x24 of the object at 0x14.
s32 func_00512748(u8 *arg0) {
    s32 (*fn)(void);

    if (D_0021EDD4 != 1 || ((u8 *)D_0021DFF0)[0x32] == 0) {
        fn = *(s32 (**)(void))(*(u8 **)(arg0 + 0x14) + 0x24);
        return fn();
    }
    return (*(u16 *)(*(u8 **)(arg0 + 0x2EF0) + 0x36) >> 11) & 0xF;
}
