/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

void *func_L00_007715F0(s32, s32, s32);             /* extern */

s32 func_L00_007292C0(s32 arg0, s32 arg1) {
    void *temp_2;

    if (arg0 != 0) {
        temp_2 = func_L00_007715F0(arg0, arg1, 1);
        if (temp_2 != NULL) {
            return *(s32 *)((u8 *)temp_2 + 0x18);
        }
    }
    return 0;
}