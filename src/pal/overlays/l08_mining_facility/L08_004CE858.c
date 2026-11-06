/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct {
    char pad0[0x20];
    u8 f20;
} Type1;

/* Tests whether the type byte is two or four. */
s32 func_L08_004CE858(Type1 *arg0)
{
    s32 result;
    u8 type;

    type = arg0->f20;
    result = 0;
    if (type == 2 || type == 4)
        result = 1;
    return result;
}
