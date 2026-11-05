#include "common.h"

extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(u32, const char *);
extern s32 func_005063C0(s32, s32);

void func_004D7118(s32 *a0, s32 *a1, s32 a2)
{
    s32 *p = a1 + 1;
    const char **table = *(const char ***)(a1 + 2);
    s32 value;

    value = func_004A2798(p, 2);
    func_005062D0(value, table[0]);
    value = func_004A2798(p, 3);
    func_005062D0(value, table[1]);
    if (a2 == a0[21]) {
        value = func_004A2798(p, 2);
        func_005063C0(value, 0x80D0D0D0);
        value = func_004A2798(p, 3);
        func_005063C0(value, 0x80D0D0D0);
    } else {
        value = func_004A2798(p, 2);
        func_005063C0(value, 0x80808080);
        value = func_004A2798(p, 3);
        func_005063C0(value, 0x80808080);
    }
}
