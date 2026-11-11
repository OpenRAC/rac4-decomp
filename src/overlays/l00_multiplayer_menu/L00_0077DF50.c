#include "net_allocator.h"

extern void func_0015DB48(s32);

/* Forward the pointer to the release helper. */
void func_L00_0077DF50(Rac4Allocator *self, void *pointer)
{
    func_0015DB48((s32)pointer);
}
