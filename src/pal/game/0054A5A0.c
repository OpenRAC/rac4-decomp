#include "common.h"

extern s32 D_00220F58[];

s32 func_0054A290(s32 arg0, s32 arg1);
s32 func_0045E850(s32 arg0);
void func_0011D920(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_00549050(void *arg0, s32 arg1, s32 arg2);

void func_0054A5A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 local[32];
    s32 selector;
    s32 address;
    s32 first;
    s32 second;
    s32 third;

    if (arg2 <= 0 || arg0 <= 0 || arg1 < 0 || arg3 < 0) {
        return;
    }
    selector = arg0 == 2 ? 0x25A5 : 0x2557;
    address = (s32)D_00220F58;
    first = func_0054A290(arg0, 0);
    second = func_0045E850(*(s16 *)(first + 8));
    third = func_0045E850(selector);
    func_0011D920(local, address, second, third, arg3 + 1);
    func_00549050(local, arg1, arg2);
}
