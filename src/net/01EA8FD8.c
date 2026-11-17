/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_01EA8F98(s32);
extern s32 D_0016819C;

s32 func_01EA8FD8(s32 arg0, u8 *arg1) {
    s32 var_s1;
    s32 var_v0;

    if (arg0 == 0x80000000) {
        var_s1 = (func_01EA8F98(D_0016819C + 4) != 0) ? -3 : 0;
        if (arg1 != NULL) {
            func_0011A370(arg1, D_0016819C + 4, 0x40);
            goto block_8;
        }
        goto block_11;
    }
    if (arg0 == -1) {
        var_s1 = (func_01EA8F98(D_0016819C + 0x104) != 0) ? -3 : 0;
        if (arg1 != NULL) {
            func_0011A370(arg1, D_0016819C + 0x104, 0x40);
            goto block_8;
        }
        goto block_11;
    }
    var_s1 = (func_01EA8F98(D_0016819C + 0x84) != 0) ? -3 : 0;
    if (arg1 != NULL) {
        func_0011A370(arg1, D_0016819C + 0x84, 0x40);
block_8:
        var_v0 = var_s1;
        if ((arg1 != NULL) && (var_s1 != 0)) {
            func_0011A518(arg1, 0, 0x40);
            goto block_11;
        }
    } else {
block_11:
        var_v0 = var_s1;
    }
    return var_v0;
}
