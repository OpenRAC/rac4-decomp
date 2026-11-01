#include "common.h"

extern void *func_004B05D0(s32);
extern void func_00502520(void *);
extern u32 D_002217E0;
/* Release the indexed item and clear its active bit. */
void func_004B07D8(s32 index)
{
    func_00502520(func_004B05D0(index));
    D_002217E0 &= ~(1u << index);
}
