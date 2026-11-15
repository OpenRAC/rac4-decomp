/* Not matching yet: 51/52 (98.08%) relocation-masked positional words; 204/208 bytes; trailing word after return omitted; callee types remain hypotheses. Reproduce: python tools/check_func.py --version pal func_L00_00541DF8 nonmatching/pal/l00_multiplayer_menu/func_L00_00541DF8.c --diff. Not part of the build. */
/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"
typedef s32 M2C_UNK;
struct Item { s32 field0; s32 field4; };

M2C_UNK func_L00_00526710(void *);                  /* extern */
void *func_L00_005267A8();                          /* extern */
s32 func_L00_00541B48(s32, s32);                    /* extern */
s32 func_L00_00548740(s32, s32, s32, M2C_UNK *);    /* extern */

void *func_L00_00541DF8(void **arg0, s32 *arg1, s32 arg2) {
    M2C_UNK sp0;
    void *var_16;

    var_16 = NULL;
    if (arg0 == NULL) {
        goto block_2;
    }
    var_16 = *arg0;
block_2:
    if (var_16 != NULL) {
        goto block_4;
    }
    var_16 = func_L00_005267A8();
    if (var_16 == NULL) {
        goto block_10;
    }
block_4:
    if (func_L00_00548740(((struct Item *) var_16)->field4, *arg1, arg2, &sp0) != 0) {
        goto block_6;
    }
    if (func_L00_00541B48(((struct Item *) var_16)->field4, 0) == 0) {
        goto block_10;
    }
block_6:
    if (arg0 == NULL) {
        goto block_8;
    }
    if (var_16 == *arg0) {
        goto block_9;
    }
block_8:
    func_L00_00526710(var_16);
block_9:
    var_16 = NULL;
block_10:
    if (arg0 == NULL) {
        goto block_15;
    }
    if (var_16 == NULL) {
        goto block_13;
    }
    *arg0 = var_16;
    return var_16;
block_13:
block_15:
    return var_16;
}
