/* Not matching yet: BYTES 5/52 (tools/try_func.py func_L00_00710750 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_004B7A38;

/* Initialise the object and hand it back. */
void *func_L00_00710750(void *arg0) {
    (*(s32 *)((u8 *)arg0 + 0x0)) = -1;
    (*(void **)((u8 *)arg0 + 0x58)) = &D_004B7A38;
    (*(s32 *)((u8 *)arg0 + 0xC)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x10)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x14)) = 0;
    (*(u8 *)((u8 *)arg0 + 0x18)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x50)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x4C)) = 0;
    return arg0;
}
