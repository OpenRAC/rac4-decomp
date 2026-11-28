/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Return the number of bytes before the string terminator. */
s32 func_L00_005339D0(const s8 *text)
{
    const s8 *start = text;
    if (*text != 0) {
        do {
            ++text;
        } while (*text != 0);
    }
    return text - start;
}
