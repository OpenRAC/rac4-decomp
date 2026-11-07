/* Not matching yet: BYTES 47/76 (tools/try_func.py func_L00_00776698 --diff). Not part of the build. (tools/try_func.py func_L00_00776698 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Reset the selection slots.
void func_L00_00776698(u8 *p) {
    s32 i;

    *(s32 *)(p + 0x1E4) = 1;
    *(u8 *)(p + 0x0) = 0;
    *(u8 *)(p + 0x14C) = 0;
    *(u8 *)(p + 0x1C0) = 0;
    for (i = 0; i < 0x14; i++) {
        *(s32 *)(p + 0x1E8 + i * 4) = -1;
        *(s32 *)(p + 0x24C + i * 4) = 0;
        *(u8 *)(p + 0x238 + i) = 0;
    }
}
