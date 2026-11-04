#include "common.h"

extern s32 D_00328890[];
extern void func_00159130(void);
extern void func_00159138(void);
extern void func_001585A8(s32);
extern s32 func_00157FA8(void);
extern void func_00161D00(void);
extern void func_0015ADC8(void);
extern void func_00158578(void);

u32 D_00220A00 = 0;
s32 D_0021EE54 = 0;

/* Run both callback loops. */
void func_004F36E8(void)
{
    u32 i;
    s32 one;
    func_00159130();
    for (i = 0; i < D_00220A00; i++) {
        func_001585A8(D_00328890[i]);
    }
    func_00159138();
    one = 1;
    while (func_00157FA8() != 0) {
        if (D_0021EE54 == one) {
            func_00161D00();
            func_0015ADC8();
        }
    }
    func_00158578();
}
