/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

/* Return the signed word at +0x10, or +0x0C when it is zero, sign-extended to 64 bits. */
s64 func_L00_0062D8B0(u8 *object) {
    s32 value = *(s32 *)(object + 0x10);

    if (!value)
        return *(s32 *)(object + 0x0C);
    return value;
}
