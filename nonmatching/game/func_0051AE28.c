/* Not matching yet: BYTES 3/196 (tools/try_func.py func_0051AE28 --diff). Not part of the build. */
/* cflags: -G0 -malign-jumps=3 */
#include "common.h"

extern s32 func_004908D0(s32, s32);
extern f32 func_00453BF8(f32, f32);
extern f32 func_0051FC38(void *, void *, s32);
extern f32 fabsf(f32);

/* Return 1 when the current state is active and within range of f12. */
s32 func_0051AE28(u8 *arg0, f32 f12)
{
    f32 d;

    if (((*(s32 *)(*(u8 **)(arg0 + 0x2F00) + 0x1A0) & func_004908D0(1, *(s32 *)(arg0 + 0x2F10))) != 0
         && *(s32 *)(arg0 + 0x2318) != 1
         && *(s32 *)(arg0 + 0x2318) != 0xE
         && *(s32 *)(arg0 + 0x2318) != 0xF)
        || (*(s32 *)(arg0 + 0x1AE0) != 0 && *(s16 *)(arg0 + 0x5F4) != 0)) {
        if (*(u8 *)(arg0 + 0x2659) != 0) {
            d = fabsf(func_0051FC38(arg0, arg0 + 0x2CF0, 0));
        } else {
            d = func_00453BF8(*(f32 *)(arg0 + 0xB8), *(f32 *)(arg0 + 0x2CE8));
        }
        if (d < f12) {
            return 0;
        }
        return 1;
    }
    return 0;
}
