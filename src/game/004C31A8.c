#include "common.h"
typedef struct {
    char pad[0x10];
    s32 f10;
    char tail[0x74 - 0x14];
} State;
typedef struct {
    s32 first, second;
} Resource;
extern State D_30B7F8[];
extern Resource D_003D2340[];
extern s32 D_221880;
extern s32 func_00505B20(void), func_004A1A60(s32 *, s32);
extern s32 func_00505328(s32, u32);
extern void func_0049C158(s32, s32, s32, s32);
void func_004C31A8(void)
{
    s32 selected = D_30B7F8[func_00505B20()].f10;
    s32 index;
    func_00505328(func_004A1A60(&D_221880, D_003D2340[selected].first), 0x80D0D0D0);
    index = func_00505B20();
    func_0049C158(index, 1, func_004A1A60(&D_221880, D_003D2340[selected].second), 0);
}
