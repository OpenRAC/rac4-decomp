/* cflags: -Wuninitialized */
#include "common.h"

s32 func_L00_005522A0(void *arg0) {
    s32 (*var_2)(s32);
    s32 var_4;
    void *var_3;

    var_3 = arg0;
    var_2 = NULL;
    if (var_3 != NULL) {
        var_2 = *(s32 (**)(s32))var_3;
        var_4 = *(s32 *)((u8 *)var_3 + 4);
        var_2 = (s32 (*)(s32)) (var_2(var_4) != 0);
    }
    return (s32) var_2;
}