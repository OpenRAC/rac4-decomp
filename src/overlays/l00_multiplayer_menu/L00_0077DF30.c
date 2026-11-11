#include "net_allocator.h"

extern void *func_0015DAC8(s32);

/* Forward the requested size to the allocation helper. */
void *func_L00_0077DF30(Rac4Allocator *self, u32 size, u32 alignment, s32 line, const char *file)
{
    return func_0015DAC8((s32)size);
}
