/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x34];
    s32 (*f34)(s32, s32, s32);
} Type1;

s32 func_01EA42D8(s32);
s32 func_01EA57B8(void);
s32 func_01EA57F8(void);
extern Type1 *D_00167F30;

s32 func_01E9E990(s32 arg0, s32 arg1, s32 arg2)
{
    s32 r;
    s32 ret;

    r = func_01EA42D8(func_01EA57B8());
    if (r != 0) {
        return r;
    }
    ret = D_00167F30->f34(arg0, arg1, arg2);
    r = func_01EA42D8(func_01EA57F8());
    if (r != 0) {
        return r;
    }
    return ret;
}
