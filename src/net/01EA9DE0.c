/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA9FE8(void *object);

s32 func_01EA9DE0(u8 *arg0) {
    s32 result;

    if (arg0 == 0) return 2;
    if (*arg0 != 1) return 2;
    result = func_01EA9FE8(arg0);
    if (result == 0) *arg0 = 0;
    return result;
}
