#include "common.h"
extern s32 D_002218B8;
extern s32 D_002218B0;
s32 D_0021F940 = 12059;
s32 D_0021F950 = 12643;
extern s32 D_003D9500[][13];
extern s32 func_00506BB8(void);
extern u32 func_004A2798(const s32 *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(u32, const char *);
s32 func_004BA330(void)
{
    s32 index = func_00506BB8();
    s32 *record = (s32 *)((u32)&D_002218B8 + ((u32)index << 4));
    u32 handle = func_004A2798(&D_002218B0, 100);
    s32 i;
    func_005062D0(handle, func_0045E850(*(s32 *)((u32)&D_0021F940 + (u32)record[1] * 4)));
    for (i = 0; i < 13; i++) {
        handle = func_004A2798(&D_002218B0, i + 180);
        func_005062D0(handle, func_0045E850(D_003D9500[record[1]][i]));
    }
    handle = func_004A2798(&D_002218B0, 182);
    return func_005062D0(handle, func_0045E850(*(s32 *)((u32)&D_0021F950 + (u32)record[2] * 4)));
}
