/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A518(void *, s32, s32);

/* clears and sizes the buffer arg3; stores 0x100 through arg4 and returns 0, or returns 0x2711 on failure */
s32 func_L00_00517CB0(void *arg0, void *arg1, void *arg2, void *arg3, s32 *arg4) {
    if (func_0011A518(arg3, 0, 0x100) == 0) {
        return 0x2711;
    }
    *arg4 = 0x100;
    return 0;
}
