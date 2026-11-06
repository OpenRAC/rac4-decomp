/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00506068(s32);                         /* extern */
s32 *func_L00_00566230(s32);                        /* extern */

s32 func_L00_00506028(s32 arg0) {
    s32 temp_a0;

    temp_a0 = (u32) (arg0 + 1) < 2U;
    if (temp_a0 != 0) {
        return func_L00_00506068(*func_L00_00566230(temp_a0));
    }
    return 0;
}
