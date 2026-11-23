/* Not matching yet: PAL WIP; level_41 .text 0x005D1780, 68B. Not part of the build. */
/*
 * Actualcount loaded directly intoa2 instead of nativev1 then copieda2; actual separate
 * exhausted-loop andnonpositive-countJR/-1 tails versus nativeoneconvergedJR/-1. Thus emitted72B,
 * native68B; resolveddataaddressesarecorrect.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 141a30feb31bd01a6c28966b27ad11727935b8778877279257f4b1a4262c4b05
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L41_005D1780 nonmatching/pal/l41_battledome_tower/func_L41_005D1780.c --diff
 */
#include "common.h"

typedef struct {
    char pad0[0x408];
    s16 f408;
    char pad40A[0x266D - 0x40A];
    u8 f266D;
    char pad266E[0x2DF0 - 0x266E];
    void *f2DF0;
    char pad2DF4[0x2F24 - 0x2DF4];
    f32 f2F24;
    char pad2F28[0x31F0 - 0x2F28];
} Type1;

extern Type1 D_00347AA0[];
extern s32 *D_0021DE2C;

s32 func_L41_005D1780(s32 arg0) {
    s32 temp_v1;
    s32 var_a1;
    Type1 *var_v1;

    temp_v1 = *D_0021DE2C;
    var_a1 = 0;
    if (temp_v1 > 0) {
        var_v1 = D_00347AA0;
loop_2:
        var_a1 += 1;
        if ((Type1 *)arg0 == var_v1) {
            return ((u8 *)var_v1)[0x2FEA];
        }
        var_v1++;
        if (var_a1 >= temp_v1) {
            return -1;
        }
        goto loop_2;
    }
    return -1;
}
