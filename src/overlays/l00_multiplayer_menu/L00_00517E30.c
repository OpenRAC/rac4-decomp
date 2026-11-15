/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A370(u8 *, u8 *, s32);

/* calls func_0011A370(arg3, arg1, arg2); on success stores arg2 through arg4 and returns 0, else returns 0x2711 */
s32 func_L00_00517E30(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3, s32 *arg4) {
    if (func_0011A370(arg3, arg1, arg2) != 0) {
        *arg4 = arg2;
        return 0;
    }
    return 0x2711;
}
