/* Not matching yet: SIZE ours 44 / retail 56 (tools/try_func.py func_01F072C8 --diff). Not part of the build. */
#include "common.h"

// Drop every entry whose key matches, clearing both words.
void func_01F072C8(u8 *p, u32 key) {
    s32 i;

    for (i = 0; i < 8; i++) {
        u8 *e = p + i * 8;

        if (*(u32 *)e == key) {
            *(u32 *)(e + 0) = 0;
            *(u32 *)(e + 4) = 0;
        }
    }
}
