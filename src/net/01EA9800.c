/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Copies one byte when both pointers are valid and returns a status.
s32 func_01EA9800(u8 *arg0, u8 *arg1) {
    s32 result = 2;
    if (arg0 == NULL) return result;
    if (arg1 == NULL) return result;
    {
        u8 value = *arg0;
        result = 0;
        *arg1 = value;
    }
    return result;
}
