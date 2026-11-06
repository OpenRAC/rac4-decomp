#include "common.h"
extern s32 D_0021EDD4;
extern s32 func_00439578(const void *, u32, u32, void (*)(s32, s32 *), s32 *);
extern void func_004E2440(s32, s32 *);
extern void func_00126E20(s32), func_00161CF0(void);
extern s32 func_00138D70(s32), func_0015ADA8(void);
extern s32 func_00157F98(void);
void func_004F2530(const void *request, s32 *result, u32 destination, u32 size)
{
    *result = -1;
    func_00439578(request, destination, size, func_004E2440, result);
    do {
        func_00126E20(0);
        func_00138D70(0);
        func_00157F98();
        if (D_0021EDD4 == 1) {
            func_00161CF0();
            func_0015ADA8();
        }
    } while (*result == -1);
}
