/* Not matching yet: BYTES 22/40 (@ee296 -O3 -G8) (tools/try_func.py func_004700C8 --diff). Not part of the build. */
/* cflags: @ee296 -O3 -G8 */
#include "common.h"
void func_004700C8(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u32 v = *(u32 *)((u8 *)arg0 + 0x3C);
    *arg1 = v & 0xFF;
    *arg2 = (v >> 8) & 0xFF;
    *arg3 = (v >> 16) & 0xFF;
}
