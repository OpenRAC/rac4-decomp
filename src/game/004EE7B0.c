#include "common.h"

extern u8 D_003D3040[];

extern void func_004EE6E8(void *);

void func_004EE7B0(void *object)
{
    *(void **)((u8 *)object + 4) = D_003D3040;
    func_004EE6E8(object);
}
