/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00408110(char *a0, char *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

/* Hand the object's 0x10 sub-block to the mode-0 pass; on success record it at +8. */
s32 func_0040A178(char *obj, s32 arg1, s32 arg2, s32 arg3)
{
    char *sub = obj + 0x10;
    s32 r = func_00408110(obj, sub, 0, arg1, *(s32 *)(obj + 0x2C), arg2, arg3);

    if (r == 0) {
        *(s32 *)(obj + 8) = (s32)sub;
    }
    return r;
}
