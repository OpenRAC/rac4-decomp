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
extern Resource D_003D21F0[];
extern s32 D_00221980;
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32);
extern u32 func_004C3D08(s32, s32);
extern s32 func_005063C0(s32, u32);
extern void func_0049CE90(s32, s32, s32, s32);
void func_004C3E20(void)
{
    s32 selected = D_0030B7F8[func_00506BB8()].selection;
    s32 id = func_004A2798(&D_00221980, D_003D21F0[selected].first);
    func_005063C0(id, func_004C3D08(selected, 1));
    {
        s32 index = func_00506BB8();
        func_0049CE90(index, 0, func_004A2798(&D_00221980, D_003D21F0[selected].second), 0);
    }
}
