/* cflags: @ee32-040921 -O2 -G0 -frename-registers */
#include "common.h"

/* Copies the word at offset 0xC to the output, or returns 2 for a null argument. */
s32 func_01EA71C8(void *object, s32 *out)
{
    s32 result = 2;
    if (object != 0 && out != 0) {
        result = 0;
        *out = *(s32 *)((char *)object + 0xC);
    }
    return result;
}
