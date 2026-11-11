#include "common.h"

extern s32 D_001D3F40[];
extern s32 D_00221E20;
extern s32 D_00221270;
extern s32 func_0044DF08(s32, u32, s64);

s32 func_0044A410(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u64 arg4, u64 arg5, s32 arg6, f32 f12, f32 f13, f32 f14, f32 f15) {
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 end1;
    s32 buffer;
    u64 first;
    u64 packet0;
    u64 packet1;
    u64 packet2;
    u64 packet3;
    u64 packet4;
    f32 scale = 16.0f;

    f14 = (f12 + f14) * scale;
    f15 = (f13 + f15) * scale;
    f12 *= scale;
    f13 *= scale;
    x0 = (s32)f14 + D_001D3F40[4] - 8;
    x1 = (s32)f12 + D_001D3F40[4] - 8;
    y0 = (s32)f13 + D_001D3F40[5] - 8;
    y1 = (s32)f15 + D_001D3F40[5] - 8;
    if (x1 > 0x9000 || x0 < 0x7000 || y0 > 0x9000 || y1 < 0x7000) {
        return 0;
    }
    if (arg6 != 0) {
        x1 = (x1 & 0xFFF0) + 8;
        x0 = (x0 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }
    end1 = arg1 + arg3;
    first = ((u64)(arg0 + arg2 - 1) << 14) | 0xA;
    packet0 = ((u64)arg0 << 4) | first |
              ((u64)arg1 << 24) | ((u64)(end1 - 1) << 34);
    packet2 = (u64)(arg1 << 20) | (u64)(arg0 << 4);
    packet3 = (u64)x1 | ((u64)y0 << 16);
    packet4 = (u64)(end1 << 20) | (u64)((arg0 + arg2) << 4);
    packet1 = (u64)x0 | ((u64)y1 << 16);
    buffer = D_00221E20;
    *(u64 *)(buffer + 0x38) = packet1;
    *(u64 *)(buffer + 0x10) = packet0;
    *(u64 *)(buffer + 8) = 0x156;
    *(u64 *)(buffer + 0x18) = (u64)arg4;
    *(u64 *)(buffer + 0x20) = packet2;
    *(u64 *)(buffer + 0x28) = packet3;
    *(u64 *)(buffer + 0x30) = packet4;
    *(u64 *)buffer = (u64)arg5;
    D_00221E20 += 0x40;
    func_0044DF08((s32)&D_00221270, 6, arg5);
    return 1;
}
