/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Type1;
extern void func_01EA91C0(u8 *, u32);
/* Format the first word and return the destination. */
u8 *func_01EB4E10(u8 *p, Type1 value)
{
    func_01EA91C0(p, value.f0);
    return p;
}
