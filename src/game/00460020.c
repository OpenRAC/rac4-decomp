#include "common.h"

/* Queries and closes a valid handle, reporting failure from either operation. */
extern s32 func_0012C888(s32, s32, const void *, s32 *);
extern s32 func_0012CA90(s32);
s32 func_00460020(s32 handle)
{
    s32 out = 0, result = 1;
    if (handle >= 0) {
        if (func_0012C888(handle, 0, 0, &out) < 0)
            result = 0;
        else if (func_0012CA90(handle) < 0)
            result = 0;
    }
    return result;
}
