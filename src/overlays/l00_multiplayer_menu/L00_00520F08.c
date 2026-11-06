/* cflags: @ee29 */
#include "common.h"
s32 func_L00_004FACD8(s32);                     /* extern */
s32 func_L00_004FAD28(s32);                     /* extern */
s32 func_L00_00520A68(s32);                         /* extern */

s32 func_L00_00520F08(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    temp_v0 = func_L00_004FACD8(0xC);
    var_v0 = 0;
    if (temp_v0 != 0) {
        temp_v0_2 = func_L00_00520A68(temp_v0);
        var_v0 = temp_v0_2;
        if (temp_v0_2 == 0) {
            func_L00_004FAD28(temp_v0);
            var_v0 = temp_v0_2;
        }
    }
    return var_v0;
}
