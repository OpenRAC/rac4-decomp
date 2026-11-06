#include "common.h"
s32 D_0021F668 = 0;
extern s32 func_004A1DE0(void), func_004E0858(void), func_00157F98(void);
extern const char *func_0045E038(s32);
extern void func_004A2148(s32), func_004A22D8(s32), func_0049B1A0(s32, s32);
extern s32 func_004E21D8(s32, s32, void *);
extern void func_0049E790(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
void func_004A2020(void)
{
    if (!func_004A1DE0()) {
        D_0021F668 = 1;
        func_0049E790(0, func_0045E038(0x377F), func_004A2148, 0, 0, 0, 0, -1.0f);
    } else {
        func_004E21D8(11, 0, 0);
        func_004E0858();
        while (func_00157F98()) {
        }
        func_004A22D8(1);
        func_0049B1A0(0, 33);
    }
}
