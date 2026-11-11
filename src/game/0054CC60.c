#include "common.h"

f32 D_00221000 = 0.13f;
f32 D_00220FFC = 0.125f;
f32 D_00221008 = 60.0f;
f32 D_0022100C = 64.0f;
f32 D_00221010 = 64.0f;
f32 D_00221014 = 0.0f;
f32 D_00221018 = 15.0f;
f32 D_00221020 = 375.0f;
f32 D_00221024 = 60.0f;
u64 D_00221028 = 0xFFFFFFFF803C3C3CULL;

extern f32 D_0022210C;
extern s32 D_001D3F40[];
extern const s32 D_003D4E38[];
extern const s32 D_003D4E58[];

extern void *memcpy(void *, const void *, u32);
extern void func_004E7990(s32, u64, s32);
extern s32 func_00448F98(s32, s32);
extern void func_0044A238(s32, s32, s32, s32, u64, s32, f32, f32, f32, f32);

void func_0054CC60(void)
{
    u64 color = D_00221028;
    s32 first[8];
    s32 second[8];
    s32 i;

    func_004E7990(0x42, 0x8000000044ULL, 0);
    func_004E7990(0x47, 0x3004B, 0);
    D_0022100C = D_00220FFC * (f32)D_001D3F40[0];
    D_00221010 = D_00220FFC * (f32)D_001D3F40[1];
    D_0022210C = D_00221000 * (f32)D_001D3F40[0] * 0.96f;
    memcpy(first, D_003D4E38, sizeof(first));
    for (i = 0; i < 8; i++) {
        D_00221014 = (f32)i * D_0022100C;
        func_0044A238(0, 0, 0x40, 0x40, color, func_00448F98(first[i], 1),
                      D_00221014, D_00221018, D_0022210C, D_00221024);
    }
    memcpy(second, D_003D4E58, sizeof(second));
    for (i = 0; i < 8; i++) {
        D_00221014 = (f32)i * D_0022100C;
        func_0044A238(0, 0, 0x40, 0x40, color, func_00448F98(second[i], 1),
                      D_00221014, D_00221020, D_0022210C, D_00221008);
    }
}
