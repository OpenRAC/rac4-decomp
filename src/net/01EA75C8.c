/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, u32);
/* Clear a sixteen-byte object. */
void *func_01EA75C8(s32 *p)
{
    void *result = func_0011A518(p, 0, 16);
    *p = 0;
    return result;
}
