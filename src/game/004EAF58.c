#include "common.h"

extern void func_0046BA60(void *, s32, s32);
extern void func_00453608(void *, s32, s32);
extern void func_004706F0(void *);
/* Preserve and clear object storage, then refresh an enabled object. */
void func_004EAF58(char *p, s32 arg)
{
    void *saved = *(void **)(p + 0xac);
    func_0046BA60(p, arg, 0);
    *(void **)(p + 0xac) = saved;
    func_00453608(saved, 0, 0x80);
    if (!(*(u16 *)(p + 0x34) & 4))
        func_004706F0(p);
}
