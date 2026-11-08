/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, u32);
/* Clear the buffer and its following word. */
void *func_01EF2C94(char *p)
{
    void *result = func_0011A518(p, 0, 0x200);
    *(s32 *)(p + 0x200) = 0;
    return result;
}
