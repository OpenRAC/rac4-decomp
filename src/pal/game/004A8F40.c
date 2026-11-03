#include "common.h"
extern s32 D_0020C710[][3];
extern s32 D_00222110;
extern void func_00453F30(void *, const void *, s32);
extern s32 func_004FF9B8(s32 *, s32, s32, s32);
void func_004A8F40(s32 index, s32 count, s32 seed)
{
    s32 values[3];
    s32 *p = D_0020C710[index];
    s32 i;
    func_00453F30(values, p, count * 4);
    for (i = 0; i < count; i++) {
        *p++ = values[func_004FF9B8(&D_00222110, i + seed, 0, count - 1)];
    }
}
