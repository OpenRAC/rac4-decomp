/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef s32 (*Transform)(u32 *, u32 *, u32 *, s32, const u32 *);
extern Transform D_L00_004A2FD0[8];
extern Transform D_L00_004A2FF0[8];
extern u32 func_L00_00546148(s32);

static inline s32 apply_transforms(s32 inverse, u32 *start, u32 *end, u32 *base, s32 operations, s32 limit, const u32 *entries) {
    s32 i = 0;
    s32 code = func_L00_00546148(operations);
    s32 count = (u32)code >> 28;

    for (; i < count; i++) {
        s32 slot = (code >> (i * 4)) & 15;
        if (inverse) {
            D_L00_004A2FD0[slot](start, end, base, limit, entries);
        } else {
            D_L00_004A2FF0[slot](start, end, base, limit, entries);
        }
    }
    return 0;
}

s32 func_L00_00533D30(u32 *start, u32 *end, u32 *base, s32 operations, s32 limit, const u32 *entries) {
    return apply_transforms(1, start, end, base, operations, limit, entries);
}

s32 func_L00_00534458(u32 *start, u32 *end, u32 *base, s32 operations, s32 limit, const u32 *entries) {
    return apply_transforms(0, start, end, base, operations, limit, entries);
}
