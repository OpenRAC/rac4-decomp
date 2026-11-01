#include "common.h"

extern u8 D_003D3080[];

extern void func_004EF730(void *);

void func_004EF7F8(void *object)
{
    *(void **)((u8 *)object + 4) = D_003D3080;
    func_004EF730(object);
}
