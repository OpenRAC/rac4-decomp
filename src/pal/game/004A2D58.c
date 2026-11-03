#include "common.h"
s32 D_0021F708 = 0;
extern s32 func_004A2B18(void), func_004E17B8(void), func_00157FA8(void);
extern const char *func_0045E850(s32);
extern void func_004A2E80(s32), func_004A3010(s32), func_0049BED8(s32, s32);
extern s32 func_004E3138(s32, s32, void *);
extern void func_0049F4C8(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
void func_004A2D58(void)
{
    if (!func_004A2B18()) {
        D_0021F708 = 1;
        func_0049F4C8(0, func_0045E850(0x377F), func_004A2E80, 0, 0, 0, 0, -1.0f);
    } else {
        func_004E3138(11, 0, 0);
        func_004E17B8();
        while (func_00157FA8()) {
        }
        func_004A3010(1);
        func_0049BED8(0, 33);
    }
}
