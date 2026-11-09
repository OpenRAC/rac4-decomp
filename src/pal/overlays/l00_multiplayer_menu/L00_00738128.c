/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 func_01E9A7C8();                            /* extern */
s32 func_L00_00738230();                            /* extern */
extern s32 D_001721E0[];

s32 func_L00_00738128(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x13A0) = func_L00_00738230();
    func_01E9A7C8();
    D_001721E0[0] = 2;
    return 0;
}