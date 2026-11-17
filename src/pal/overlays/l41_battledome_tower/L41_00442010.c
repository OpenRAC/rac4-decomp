/* cflags: -Wa,-mips4 */
#include "common.h"

/* Evaluate the existing whole-file interlocked-transfer assembler profile. */
extern f32 func_L41_00441CE0(s32 selector);
extern void func_L41_00441D48(void *target, f32 value);
extern void func_L41_00441E20(void *target, s32 value_a, s32 value_b);

s32 func_L41_00442010(void *object) {
    void *state;
    s32 selector;
    s32 opposite;
    f32 previous_scaled;
    f32 current;

    state = *(void **)((u8 *)object + 0xAC);
    selector = *(s32 *)((u8 *)state + 8);
    if (selector != 10 &&
        *(f32 *)state == func_L41_00441CE0(selector) &&
        ((opposite = *(s32 *)((u8 *)state + 4), opposite == 10) ||
         *(f32 *)state == -func_L41_00441CE0(opposite))) {
        func_L41_00441E20(object, *(s32 *)((u8 *)state + 8),
                         *(s32 *)((u8 *)state + 0x10));
        goto cache_current;
    }
    previous_scaled = *(f32 *)((u8 *)state + 0x1C) * 4.0f;
    current = *(f32 *)state;
    if ((s32)previous_scaled != (s32)(current * 4.0f)) {
        func_L41_00441D48(object, current);
cache_current:
        *(f32 *)((u8 *)state + 0x1C) = *(f32 *)state;
    }
    return 0;
}
