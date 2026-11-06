/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

extern s32 func_L00_00541F18(s32 value);
extern s32 func_0011A1A0(void);

/* Classify the stored value only for the two supported selectors. */
s32 func_L00_00541ED8(s32 selector)
{
    s32 supported;

    supported = (u32)selector + 1U < 2U;
    if (supported != 0) {
        return func_L00_00541F18(*(s32 *)func_0011A1A0());
    }
    return 0;
}
