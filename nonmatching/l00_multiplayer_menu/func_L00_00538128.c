/* Not matching yet: BYTES 31/84 (tools/try_func.py func_L00_00538128 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

// Drop the empty slots at the end of the list.
void func_L00_00538128(u8 *p) {
    u64 *e;
    s32 count;

    if (*(s32 *)(p + 0x4) <= 0) {
        return;
    }
    e = (u64 *)((u8 *)(*(u8 **)p) + (*(s32 *)(p + 0x4) * 8 - 8));
    if (*e != 0) {
        return;
    }
    do {
        count = *(s32 *)(p + 0x4) - 1;
        *(s32 *)(p + 0x4) = count;
        if (count <= 0) {
            return;
        }
        e--;
    } while (*e == 0);
}
