/* cflags: @ee29 */
#include "common.h"
s32 func_L00_004F84C8(s32, s32, s32, s32, s32); /* extern */
void *func_L00_00517808();                          /* extern */

s32 func_L00_00519658(s32 arg0) {
    s32 (*temp_v0)(s32);

    temp_v0 = (*(s32 (**)(s32))((u8 *)(func_L00_00517808()) + 0x28));
    if (temp_v0 == NULL) {
        func_L00_004F84C8(0xA, 0x6B, 0xE, 0, 0);
        return -1;
    }
    return temp_v0(arg0);
}
