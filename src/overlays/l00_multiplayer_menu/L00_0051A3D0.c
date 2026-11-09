/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 func_L00_00540868(void);
s32 func_L00_0051A3D0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *vtable;
    if (arg1 != 0 && func_L00_00540868() == 0) return 0;
    vtable = *(u8 **)arg0;
    ((void (*)(void *, s32, s32, s32))(*(void **)(vtable + 0x10)))(arg0, arg2, arg3, 1);
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 4) = 1;
    return 1;
}
