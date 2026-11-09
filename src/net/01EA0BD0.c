/* cflags: -G0 */
#include "common.h"
extern s32 func_01EAB210(u32 *);
/* Reads and returns the timer value. */
s32 func_01EA0BD0(void)
{
    u32 val;
    func_01EAB210(&val);
    return (s32)val;
}