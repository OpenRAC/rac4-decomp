/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00538190();                            /* extern */
s32 func_L00_005383D0(s32, s32);                    /* extern */

s32 func_L00_00538390(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_L00_00538190();
    if (temp_v0 == 0) {
        return 0;
    }
    return func_L00_005383D0(temp_v0, arg0);
}
