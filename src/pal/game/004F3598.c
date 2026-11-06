#include "common.h"
extern s32 D_0021EE54;
extern s32 func_00439B70(const void *, u32, u32, void (*)(s32, s32 *), s32 *);
extern void func_004E33A0(s32, s32 *);
extern void func_00126E20(s32), func_00161D00(void);
extern s32 func_00138D70(s32), func_0015ADC8(void);
extern s32 func_00157FA8(void);
void func_004F3598(const void *request, s32 *result, u32 destination, u32 size)
{
    *result = -1;
    func_00439B70(request, destination, size, func_004E33A0, result);
    do {
        func_00126E20(0);
        func_00138D70(0);
        func_00157FA8();
        if (D_0021EE54 == 1) {
            func_00161D00();
            func_0015ADC8();
        }
    } while (*result == -1);
}
