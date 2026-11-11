#include "common.h"
extern s32 D_002217B8;
extern s32 D_002217B0;
s32 D_0021F8A0 = 12059;
s32 D_0021F8B0 = 12643;
extern s32 D_003D9488[][13];
extern s32 func_00505B20(void);
extern u32 func_004A1A60(const s32 *, s32);
extern const char *func_0045E038(s32);
extern s32 func_00505238(u32, const char *);
s32 func_004B9440(void)
{
    s32 index = func_00505B20();
    s32 *record = (s32 *)((u32)&D_002217B8 + ((u32)index << 4));
    u32 handle = func_004A1A60(&D_002217B0, 100);
    s32 i;
    func_00505238(handle, func_0045E038(*(s32 *)((u32)&D_0021F8A0 + (u32)record[1] * 4)));
    for (i = 0; i < 13; i++) {
        handle = func_004A1A60(&D_002217B0, i + 180);
        func_00505238(handle, func_0045E038(D_003D9488[record[1]][i]));
    }
    handle = func_004A1A60(&D_002217B0, 182);
    return func_00505238(handle, func_0045E038(*(s32 *)((u32)&D_0021F8B0 + (u32)record[2] * 4)));
}
