/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00500D30(s32);                     /* extern */
s32 func_L00_0051CD28(s32, s32);                    /* extern */

s32 func_L00_00507DC8(s32 arg0, s32 arg1) {
    if (func_L00_00500D30(2) != 0) {
        return func_L00_0051CD28(arg0, arg1);
    }
    return 0;
}
