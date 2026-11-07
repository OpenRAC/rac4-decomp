#include "common.h"

extern void func_L00_006043E8(void);
extern s32 D_00222780;

s32 func_L06_00569140(u16 a1)
{
    s32 result;
    s32 v2;

    if (!D_00222780)
        return 0;
    result = 0;
    if (*(s32 *)(D_00222780 + 12308) >= (s64)a1) {
        v2 = *(u32 *)(D_00222780 + 12312) + 32 * a1;
        if (((*(u8 *)(v2 + 2) ^ 1) & 1) != 0) {
            return 0;
        } else {
            *(u16 *)(v2 + 2) &= ~1u;
            func_L00_006043E8();
            return 1;
        }
    }
    return result;
}