/* Not matching yet: BYTES 21/32 (tools/try_func.py func_L01_00592CD0 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns2 */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

/* Store the arguments into the object and clear the words after them. */
void func_L01_00592CD0(void *arg0, s32 arg1, s32 arg2, f32 arg3) {
    (*(u8 *)((u8 *)arg0 + 0x19)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x20)) = 0;
    (*(u128 *)((u8 *)arg0 + 0x0)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x1C)) = arg3;
    (*(s32 *)((u8 *)arg0 + 0x14)) = arg2;
    (*(s32 *)((u8 *)arg0 + 0x10)) = arg1;
}
