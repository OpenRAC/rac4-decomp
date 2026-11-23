/* Not matching yet: PAL WIP; level_41 .text 0x00412740, 336B. Not part of the build. */
/*
 * Native copies normalized equality from v0 to v1 before ANDI; best compiler writes SLTIU directly
 * to v1 and omits this copy. No additional required semantic computation is known. Ordinary tested
 * graphs coalesce it; no fake copy/padding/register/type/flag workaround proposed. This is an
 * unresolved concrete codegen residual, not a global compiler-impossibility proof.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b6f329e3c3d74f2e6d225900f50e2f0c470bad7003bfde71f4ba99a93de0b237
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L41_00412740 nonmatching/pal/l41_battledome_tower/func_L41_00412740.c --diff
 */
#include "common.h"
#include "pal/mask_state.h"

extern s32 D_0021E714;
s32 func_L41_00412458(s32 arg0);
s32 func_L41_00411F68(void *arg0);
s32 func_L41_00411FC8(u8 *arg0);
s32 func_L41_00411FD8(u8 *arg0);
s32 func_L41_00411FE8(u8 *arg0);

/* Common status result across guards and the two helper branches. */
s32 func_L41_00412740(void *arg0, s32 arg1)
{
    u8 *object = arg0;
    void *link;
    s32 blocked;
    s32 comparison;
    s32 result = 0;
    f32 left;
    f32 right;
    if (func_L41_00412458(arg1) != 0)
        goto done;
    if (*(s32 *)(object + 0x25D4) == 0x14)
        goto done;
    link = *(void **)(object + 0x2EFC);
    blocked = 0;
    if (link != NULL) {
        if (*((u8 *)link + 0x27B) != 0)
            blocked = *(s32 *)(object + 0x25CC) == 0x31;
    }
    if ((blocked & 0xFF) != 0)
        goto done;
    if (*(s32 *)(object + 0x25CC) == 0x31)
        goto done;
    if (!(0.0f < *(f32 *)(object + 0x2E20)))
        goto done;
    if (func_L41_00411F68((void *)arg1) != 0) {
        result = 1;
        goto done;
    }
    if (func_L41_00411FC8((u8 *)arg1) != 0) {
        result = 1;
        goto done;
    }
    if (func_L41_00411FD8((u8 *)arg1) != 0) {
        left = *(f32 *)(object + 0x2E20);
        right = *(f32 *)(object + 0x2F24);
        comparison = 1;
        if (!(left < right))
            comparison = 0;
        result = comparison;
        if (D_0021E714 == 1) {
            if (*((u8 *)D_0021E078 + 0x32) != 0) {
                if (*(s32 *)(object + 0x2F14) == 1)
                    result = 0;
            }
        }
    } else {
        result = func_L41_00411FE8((u8 *)arg1) != 0;
    }
done:
    return result;
}
