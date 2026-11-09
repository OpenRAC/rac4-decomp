/* cflags: @ee296 -O2 -G0 -fno-delayed-branch -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x18];
    s32 f18;
} Type1;

void func_004E2554(s32 arg0, s32 arg1, s32 *arg2, Type1 *arg3)
{
    arg3->f18 = *arg2;
}
