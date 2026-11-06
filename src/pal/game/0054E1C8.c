#include "common.h"

f32 D_002210A0 = 0.13f;
f32 D_0022109C = 0.125f;
f32 D_002210A8 = 60.0f;
f32 D_002210AC = 64.0f;
f32 D_002210B0 = 64.0f;
f32 D_002210B4 = 0.0f;
f32 D_002210B8 = 15.0f;
f32 D_002210C0 = 375.0f;
f32 D_002210C4 = 60.0f;
u64 D_002210C8 = 0xFFFFFFFF803C3C3CULL;

extern f32 D_0022220C;
extern s32 D_001D3FC0[];
extern const s32 D_003D4E78[];
extern const s32 D_003D4E98[];

extern void *memcpy(void *, const void *, u32);
extern void func_004E88B8(s32, u64, s32);
extern s32 func_004495D8(s32, s32);
extern void func_0044A8E0(s32, s32, s32, s32, u64, s32, f32, f32, f32, f32);

void func_0054E1C8(void)
{
    u64 color = D_002210C8;
    s32 first[8];
    s32 second[8];
    s32 i;

    func_004E88B8(0x42, 0x8000000044ULL, 0);
    func_004E88B8(0x47, 0x3004B, 0);
    D_002210AC = D_0022109C * (f32)D_001D3FC0[0];
    D_002210B0 = D_0022109C * (f32)D_001D3FC0[1];
    D_0022220C = D_002210A0 * (f32)D_001D3FC0[0] * 0.96f;
    memcpy(first, D_003D4E78, sizeof(first));
    for (i = 0; i < 8; i++) {
        D_002210B4 = (f32)i * D_002210AC;
        func_0044A8E0(0, 0, 0x40, 0x40, color, func_004495D8(first[i], 1),
                      D_002210B4, D_002210B8, D_0022220C, D_002210C4);
    }
    memcpy(second, D_003D4E98, sizeof(second));
    for (i = 0; i < 8; i++) {
        D_002210B4 = (f32)i * D_002210AC;
        func_0044A8E0(0, 0, 0x40, 0x40, color, func_004495D8(second[i], 1),
                      D_002210B4, D_002210C0, D_0022220C, D_002210A8);
    }
}
