/* cflags: @ee29 */
#include "common.h"
s32 func_L00_004FF4A8(void *, s32);         /* extern */
s32 func_L00_00500CE0();                      /* extern */

void func_L00_004FFAC0(void *arg0) {
    if (!(func_L00_00500CE0() & 0x3000) || (func_L00_00500CE0(arg0) & 0x4000)) {
        func_L00_004FF4A8(arg0, 0);
    }
    (*(s32 (**)(void *))((u8 *)((*(void **)((u8 *)(arg0) + 8))) + 0x14))(arg0);
}
