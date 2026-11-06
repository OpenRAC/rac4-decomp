#include "common.h"
typedef struct {
    char pad[0xC];
    s32 selection;
    char tail[0x64];
} State;
typedef struct {
    s32 first, second, third;
} Resource;
extern State D_0030B7F8[];
extern Resource D_003D2180[];
extern s32 D_00221880;
extern s32 func_00505B20(void), func_004A1A60(s32 *, s32);
extern u32 func_004C2EE0(s32, s32);
extern s32 func_00505328(s32, u32);
extern void func_0049C158(s32, s32, s32, s32);
void func_004C2FF8(void)
{
    s32 selected = D_0030B7F8[func_00505B20()].selection;
    s32 id = func_004A1A60(&D_00221880, D_003D2180[selected].first);
    func_00505328(id, func_004C2EE0(selected, 1));
    {
        s32 index = func_00505B20();
        func_0049C158(index, 0, func_004A1A60(&D_00221880, D_003D2180[selected].second), 0);
    }
}
