#include "common.h"

extern const char D_00220EB8[];

void *func_00548D28(s32 arg0, s32 arg1);
const char *func_0045E038(s32 arg0);
s32 func_0011D920(char *, const char *, ...);
void func_00547B08(const char *arg0, s32 arg1, s32 arg2);

void func_00549038(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    char local[128];
    s32 selector;
    const char *address;
    u8 *first;
    const char *second;
    const char *third;

    if (arg2 <= 0 || arg0 <= 0 || arg1 < 0 || arg3 < 0) {
        return;
    }
    selector = arg0 == 2 ? 0x25A5 : 0x2557;
    address = D_00220EB8;
    first = func_00548D28(arg0, 0);
    second = func_0045E038(*(s16 *)(first + 8));
    third = func_0045E038(selector);
    func_0011D920(local, address, second, third, arg3 + 1);
    func_00547B08(local, arg1, arg2);
}
