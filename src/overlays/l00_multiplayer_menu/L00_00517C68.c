/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A518(void *, s32, s32);

/* clears and sizes the buffer arg1; stores 0x80 through arg2 and returns 0, or returns 0x2711 on failure */
s32 func_L00_00517C68(void *arg0, void *arg1, s32 *arg2) {
    if (func_0011A518(arg1, 0, 0x80) == 0) {
        return 0x2711;
    }
    *arg2 = 0x80;
    return 0;
}
