#include "common.h"
typedef struct State {
    u16 a, count;
    u8 pad[0x10];
    s32 last;
} State;
extern State D_001DFCC0;
extern s32 D_0021DE3C, D_0021DE40;
typedef s32 (*Primary)(s32);
typedef void (*Secondary)(s32);
Primary D_002209D8 = 0;
Secondary D_002209DC = 0;
u32 D_002209F4 = 0;
extern void func_004916B0(void);
s32 func_004F4868(s32 value)
{
    s32 result;
    D_0021DE3C = 6;
    D_001DFCC0.count++;
    result = D_002209D8(value);
    if (D_002209F4 & 16)
        func_004916B0();
    if (D_002209DC)
        D_002209DC(value);
    D_0021DE40 = (s32)((u32)D_0021DE40 + 1);
    return result;
}
