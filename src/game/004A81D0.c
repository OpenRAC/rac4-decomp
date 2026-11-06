#include "common.h"
extern s32 D_0020C690[][3];
extern s32 D_00222010;
extern void func_00453718(void *, const void *, s32);
extern s32 func_004FE948(s32 *, s32, s32, s32);
void func_004A81D0(s32 index, s32 count, s32 seed)
{
    s32 values[3];
    s32 *p = D_0020C690[index];
    s32 i;
    func_00453718(values, p, count * 4);
    for (i = 0; i < count; i++) {
        *p++ = values[func_004FE948(&D_00222010, i + seed, 0, count - 1)];
    }
}
