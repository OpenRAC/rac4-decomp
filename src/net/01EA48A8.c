/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA06A8(s32 *);
/* Dispatch the selected word if the array exists. */
void func_01EA48A8(s32 *p, u32 index)
{
    if (p) func_01EA06A8(p + index);
}
