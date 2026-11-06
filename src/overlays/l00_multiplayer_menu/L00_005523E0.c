/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00553698(s32);                         /* extern */

s32 func_L00_005523E0(void *arg0) {
    s32 temp_s1;
    s32 temp_v0;

    temp_s1 = (*(s32 *)((u8 *)(arg0) + 8));
    temp_v0 = func_L00_00553698(arg0 + 8);
    if (temp_v0 == 0) {
        if (temp_s1 != (*(s32 *)((u8 *)(arg0) + 8))) {
            (*(s32 *)((u8 *)(arg0) + 0xD0)) = temp_s1;
        }
    }
    return temp_v0;
}
