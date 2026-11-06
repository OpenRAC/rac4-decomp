#include "common.h"
typedef struct State {
    u16 a, count;
    u8 pad[0x10];
    s32 last;
} State;
extern State D_001DFC40;
extern s32 D_0021DDB4, D_0021DDB8;
typedef s32 (*Primary)(s32);
typedef void (*Secondary)(s32);
Primary D_00220938 = 0;
Secondary D_0022093C = 0;
u32 D_00220954 = 0;
extern void func_00490BC8(void);
s32 func_004F3800(s32 value)
{
    s32 result;
    D_0021DDB4 = 6;
    D_001DFC40.count++;
    result = D_00220938(value);
    if (D_00220954 & 16)
        func_00490BC8();
    if (D_0022093C)
        D_0022093C(value);
    D_0021DDB8 = (s32)((u32)D_0021DDB8 + 1);
    return result;
}
