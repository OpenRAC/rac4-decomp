/* Not matching yet: BYTES 48/52 (tools/try_func.py func_01F072C8 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Drop every entry whose key matches, clearing both words.
void func_01F072C8(u8 *p, s32 key) {
    s32 i;
    u8 *e;

    i = 0;
    do {
        e = p + i * 8;
        i++;
        if (*(s32 *)e == key) {
            *(s32 *)(e + 0) = 0;
            *(s32 *)(e + 4) = 0;
        }
    } while (i < 8);
}
