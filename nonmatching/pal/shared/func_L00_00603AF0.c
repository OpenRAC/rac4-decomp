/* Not matching yet: PAL WIP; level_00 .text 0x00603AF0, 408B. Not part of the build. */
/*
 * Native has oneNOPbetweenSUB.S andeachnearDIV.S, andtwoNOPsbetweenfarSUB.S/commonfarDIV.S;
 * actualh05defaultemissionhasnone. Branchimmediatedifferencesarecorrespondingspacingdeltas.
 * Actualrawbinarylengthdiffers16B.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 4e57724036501d1232bc0f185be69ed4ca5c749f952bae12fbfa20ac98c0965f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00603AF0 nonmatching/pal/shared/func_L00_00603AF0.c --diff
 */
#include "common.h"

f32 func_L00_00603AF0(f32 *first, f32 *second)
{
    f32 exit = 1.0f;
    s32 axis = 0;
    f32 entry = 0.0f;
    f32 lower = -1.0f;
    f32 upper = exit;

    do {
        f32 a = *first;
        f32 b = *second;
        f32 far;
        f32 near;
        f32 difference;

        if (a < b) {
            if (a > upper || b < -1.0f) {
reject:
                return -1.0f;
            }
            difference = b - a;
            if (a < -1.0f)
                near = (-1.0f - a) / difference;
            else
                near = 0.0f;
            far = 1.0f;
            if (!(b > 1.0f))
                goto update_interval;
            goto correct_far;
        } else {
            if (b > 1.0f || a < lower)
                goto reject;
            difference = b - a;
            if (a > 1.0f)
                near = (1.0f - a) / difference;
            else
                near = 0.0f;
            far = -1.0f;
            if (b < -1.0f) {
correct_far:
                far = (far - a) / difference;
                goto update_interval;
            }
            far = 1.0f;
        }
update_interval:
        if (entry < near)
            entry = near;
        if (far < exit)
            exit = far;
        if (exit < entry)
            goto reject;
        axis++;
        second++;
        first++;
    } while (axis < 3);
    return entry;
}
