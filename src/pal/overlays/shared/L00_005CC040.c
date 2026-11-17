#include "common.h"

typedef struct TexInfo {
    s32 z;
    u8 pad4[0x10];
    s16 *index;
    u8 *entries;
} TexInfo;

extern u8 *D_00222FE0;
extern TexInfo D_00244FB0;
extern s32 D_001D3FC0[];

u64 func_L00_005CBE00(s32);

// Add PAL C for func_L00_005CC040
void func_L00_005CC040(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 alpha) {
    u8 *e;
    u8 *p;
    s32 tw;
    s32 th;

    e = D_00244FB0.entries + D_00244FB0.index[idx * 2 + 1] * 8;
    tw = 1 << e[6];
    th = 1 << e[7];
    *(u32 *)(D_00222FE0 + 0) = 0x10000005;
    *(u32 *)(D_00222FE0 + 4) = 0;
    *(u32 *)(D_00222FE0 + 8) = 0;
    *(u32 *)(D_00222FE0 + 12) = 0x50000005;
    p = D_00222FE0 + 16;
    D_00222FE0 = p;
    *(u64 *)(p + 0x0) = 0x7400000000008001;
    *(u64 *)(p + 0x8) = 0x5353106;
    *(u64 *)(p + 0x10) = func_L00_005CBE00(idx);
    *(u64 *)(p + 0x18) = 0x156;
    *(u64 *)(p + 0x20) = ((s64)alpha << 24) | 0x7F7F7F;
    *(u64 *)(p + 0x28) = 0;
    *(u64 *)(p + 0x30) = (x * 16 + D_001D3FC0[4] - 8) | ((s64)(y * 16 + D_001D3FC0[5] - 8) << 16) | ((s64)D_00244FB0.z << 32);
    *(u64 *)(p + 0x38) = (th << 20) + (tw << 4);
    *(u64 *)(p + 0x40) = ((x + w) * 16 + D_001D3FC0[4] - 8) | ((s64)((y + h) * 16 + D_001D3FC0[5] - 8) << 16) | ((s64)D_00244FB0.z << 32);
    *(u64 *)(p + 0x48) = 0;
    D_00222FE0 += 0x50;
}
