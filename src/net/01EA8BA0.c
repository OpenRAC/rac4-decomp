/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Type1;
typedef s32 (*Type2)(Type1);
typedef struct { char pad0[0x54]; Type2 f54; } Type3;
extern s32 D_00167F34[];
/* Forward the value to the installed network callback. */
s32 func_01EA8BA0(Type1 value)
{
    return ((Type3 *)D_00167F34[0])->f54(value);
}
