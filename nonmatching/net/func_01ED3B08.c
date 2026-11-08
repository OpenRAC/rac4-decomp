/* Not matching yet: SIZE ours 72 / retail 88 (tools/try_func.py func_01ED3B08 --diff). Not part of the build. */
#include "common.h"

// Reset the queue header and its 0x40 entries.
void func_01ED3B08(u8 *p) {
    s32 i;

    *(s32 *)(p + 0x0) = 1;
    *(s32 *)(p + 0x4) = 0xFFFFFF;
    *(s32 *)(p + 0x8) = 0;
    *(s32 *)(p + 0xC) = 0;
    for (i = 0; i < 0x40; i++) {
        *(s32 *)(p + 0x10 + i * 0x100) = 0;
        *(s32 *)(p + 0x14 + i * 0x100) = 0;
    }
}
