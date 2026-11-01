/* cflags: @ee29 -O2 -G0 */
#include "common.h"

// Returns +0x10 when nonzero, otherwise the value at +0x0C.
s32 func_L00_0062DA80(void *object)
{
    s32 value = *(s32 *)((u8 *)object + 0x10);

    if (value == 0) {
        return *(s32 *)((u8 *)object + 0x0C);
    }
    return value;
}
