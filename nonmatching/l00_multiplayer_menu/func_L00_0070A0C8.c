/* Not matching yet: BYTES 9/108 (tools/try_func.py func_L00_0070A0C8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void *D_00220A28;

/* Swaps the global owner for arg0, calling the old and new owners' hooks. */
void *func_L00_0070A0C8(void *arg0) {
    void *temp;

    temp = D_00220A28;
    if (temp != 0) {
        (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)temp + 0x58) + 0x20))(temp, 1, 0);
    }
    if (arg0 != 0) {
        (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)arg0 + 0x58) + 0x20))(arg0, 1, 0);
    }
    D_00220A28 = arg0;
    return temp;
}
