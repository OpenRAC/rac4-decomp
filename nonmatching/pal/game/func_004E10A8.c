/* Not matching yet: PAL WIP; main .text 0x004E10A8, 252B. Not part of the build. */
/*
 * Nativeentryrecordcopy v1<-a0 absent inours; pointer/baseline registers swapped. NativebaselineLW
 * physicallybeforemodeBEQ, ours inordinaryBEQdelay (stillunconditional). Native early
 * boundreturntails plus likelyconditionalCload differ fromforward commonboundtails/NOPs.
 * CommonDIV/returnsharing shortensactualbody; FPregisters/scheduling differ. No missing
 * runtimepath operation/store/helper/data symbol alleged aftert02.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: f4503b659d3557a813b0aae9fc20be190eefbabd352c2fd0babe3401f812b25e
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004E10A8 nonmatching/pal/game/func_004E10A8.c --diff
 */
#include "common.h"

extern s32 D_0021DE98;

s32 func_004E10A8(void *record, s32 curve_override, f32 t, f32 lo, f32 hi)
{
    s32 mode = D_0021DE98;
    s32 baseline = *(s32 *) ((s8 *) record + 8);
    s32 suppress = 0;
    s32 upper;
    s32 difference;
    s32 adjustment;
    f32 numerator;
    f32 denominator;
    f32 span;
    f32 numerator_squared;
    f32 denominator_squared;

    if ((mode == 0) || (mode >= 40)) {
        suppress = 1;
    }
    if (suppress != 0) {
        baseline = 0;
    }

    if ((*(u8 *) ((s8 *) record + 0x19) & 1) || (curve_override != 0)) {
        if (t <= lo) {
            goto upper_result;
        }
        if (hi <= t) {
            goto baseline_result;
        }
        upper = *(s32 *) ((s8 *) record + 0xC);
        numerator = hi - t;
        denominator = hi - lo;
        difference = (s32) ((u32) upper - (u32) baseline);
        span = (f32) difference;
        numerator_squared = numerator * numerator;
        denominator_squared = denominator * denominator;
        adjustment = (s32) ((numerator_squared * span) / denominator_squared);
        return (s32) ((u32) baseline + (u32) adjustment);
    }

    if (t <= lo) {
        goto upper_result;
    }
    if (hi <= t) {
        goto baseline_result;
    }
    upper = *(s32 *) ((s8 *) record + 0xC);
    numerator = hi - t;
    denominator = hi - lo;
    difference = (s32) ((u32) upper - (u32) baseline);
    span = (f32) difference;
    adjustment = (s32) ((numerator * span) / denominator);
    return (s32) ((u32) baseline + (u32) adjustment);

upper_result:
    return *(s32 *) ((s8 *) record + 0xC);
baseline_result:
    return baseline;
}
