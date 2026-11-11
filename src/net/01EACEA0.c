/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
/* Clears and initializes the record. */
void func_01EACEA0(s32 *p, s32 x)
{
    func_0011A518(p, 0, 0x200);
    p[0] = x;
}
