#include "common.h"
void *func_L00_0069D9B8(s32);                       /* extern */

f32 func_L00_00715648(void *arg0) {
    f32 var_f0;
    void *var_v0;

    var_v0 = func_L00_0069D9B8((*(s32 *)((u8 *)(arg0) + 0x5C)));
    if ((var_v0 != NULL) || (var_v0 = func_L00_0069D9B8((*(s32 *)((u8 *)(arg0) + 0x14))), var_f0 = 1.0f, (var_v0 != NULL))) {
        var_f0 = (*(f32 *)((u8 *)(var_v0) + 0x1C));
    }
    return var_f0;
}
