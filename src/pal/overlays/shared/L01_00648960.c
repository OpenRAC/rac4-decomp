#include "common.h"

extern void func_004F6EC8();
extern void func_00449A28(void *, void (*)(), s32);
extern s32 D_00222B98;

void func_L01_00648960(s32 arg0)
{
    func_00449A28(&D_00222B98, func_004F6EC8, arg0);
}