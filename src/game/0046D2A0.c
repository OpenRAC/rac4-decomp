#include "common.h"

extern u8 D_00117A60[];
extern s32 D_00221408;
extern void func_004E7450(u8 *);
extern void func_004E7990(s32, u64, s32);
extern void func_00126E20(s32);
extern void func_0046D168(void);
extern s32 func_00470BF0(s32, s32, s32, s32);
extern void func_0046D138(void);

void func_0046D2A0(s32 arg0, s32 arg1, s32 arg2)
{
    func_004E7450(D_00117A60);
    func_004E7990(0x47, 0x5360B, 0);
    func_00126E20(0);
    func_0046D168();
    D_00221408 = func_00470BF0(arg0, D_00221408, arg1, arg2);
    func_0046D138();
    D_00221408 -= 0x10;
}
