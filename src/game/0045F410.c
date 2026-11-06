#include "common.h"

/* Run the two operations for a valid handle and preserve negative errors. */
s32 func_0012C888(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
extern s32 func_0012CA90(s32);
s32 func_0045F410(s32 a)
{
    s32 out;
    s32 result = -1;
    if (a >= 0) {
        result = func_0012C888(a, 0, 0, &out);
        if (result >= 0) {
            result = func_0012CA90(a);
            if (result >= 0)
                result = 0;
        }
    }
    return result;
}
