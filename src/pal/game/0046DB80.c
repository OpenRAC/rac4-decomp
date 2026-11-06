#include "common.h"

extern u8 D_00117A60[];
extern s32 D_00221508;
extern void func_004E8378(u8 *);
extern void func_004E88B8(s32, u64, s32);
extern void func_00126E20(s32);
extern void func_0046DA48(void);
extern s32 func_004714D0(s32, s32, s32, s32);
extern void func_0046DA18(void);

void func_0046DB80(s32 arg0, s32 arg1, s32 arg2)
{
    func_004E8378(D_00117A60);
    func_004E88B8(0x47, 0x5360B, 0);
    func_00126E20(0);
    func_0046DA48();
    D_00221508 = func_004714D0(arg0, D_00221508, arg1, arg2);
    func_0046DA18();
    D_00221508 -= 0x10;
}
