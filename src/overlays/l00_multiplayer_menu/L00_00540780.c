/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern s32 func_L00_005405F8(s32, void *, s32);
/* Clears *out, then if the object has a pending value, hands it to the reader and stores the result. */
s32 func_L00_00540780(s32 *object, s32 argument, s32 *out) {
    s32 result;
    *out = 0;
    if (*object != 0) {
        result = func_L00_005405F8(argument, object + 2, *object);
        if (result < 0) return -1;
        *object = 0;
        *out = result;
        return 1;
    }
    return 1;
}
