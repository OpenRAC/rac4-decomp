#include "common.h"

extern void func_0046C320(void *, s32, s32);
extern void func_00453E20(void *, s32, s32);
extern void func_00470FD0(void *);
/* Preserve and clear object storage, then refresh an enabled object. */
void func_004EBEA8(char *p, s32 arg)
{
    void *saved = *(void **)(p + 0xac);
    func_0046C320(p, arg, 0);
    *(void **)(p + 0xac) = saved;
    func_00453E20(saved, 0, 0x80);
    if (!(*(u16 *)(p + 0x34) & 4))
        func_00470FD0(p);
}
