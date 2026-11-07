/* Not matching yet: BYTES 32/44 (tools/try_func.py func_L01_0063B1B8 --diff). Not part of the build. */
#include "common.h"

// Release index `i` from the table and drop the reference count.
void func_L01_0063B1B8(u8 *p, s32 i) {
    u8 *e = p + i * 4;

    *(s32 *)(e + 0x0) = 0;
    *(s32 *)(e + 0x100) = 0;
    if (--*(s32 *)(p + 0x220) == 0) {
        *(s32 *)(p + 0x224) = 0;
    }
}
