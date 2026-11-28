/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u32 func_L00_00546148(s32);
extern s32 (*D_L00_004A2FF0[8])(u32 *, u32 *, u32 *, s32, const u32 *);

/* Apply each selected transform to the same input range. */
s32 func_L00_00534458(u32 *start, u32 *end, u32 *base, s32 operations, s32 limits, const u32 *entries) {
    s32 i = 0;
    s32 code = func_L00_00546148(operations);
    s32 count = (u32)code >> 28;

    for (; i < count; i++) {
        D_L00_004A2FF0[(code >> (i * 4)) & 15](start, end, base, limits, entries);
    }
    return 0;
}
