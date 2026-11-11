/* cflags: @ee296 -Os -G8 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "net_allocator.h"
/* Forward a release request and return the updated counter. */
s32 func_01EF0550(s32 object, s32 pointer_word)
{
    Rac4Allocator *p = (Rac4Allocator *)object;
    p->f1041c->f10(p, (void *)pointer_word);
    return (s32)++p->f10418;
}
