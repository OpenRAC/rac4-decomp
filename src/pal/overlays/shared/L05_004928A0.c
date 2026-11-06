#include "common.h"

extern void func_L05_00493300(u8 *object);

void func_L05_004928A0(u8 *object)
{
    *(u16 *)(object + 0x6A) += 1;
    func_L05_00493300(object);
}
