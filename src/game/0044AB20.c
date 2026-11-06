#include "common.h"
typedef struct {
    u8 unknown0[0x10];
    s32 x;
    s32 y;
} Screen;
extern Screen D_001D3F40[];
extern void func_0044AA58(const u64 *vertices, const s32 *colors);
void func_0044AB20(s32 x1, s32 y1, s32 x2, s32 y2, u32 upper, const s32 *colors)
{
    u64 vertices[4];
    u64 high = (u64)upper << 32;
    x1 = (s32)(((u32)x1 << 4) + (u32)D_001D3F40[0].x - 8);
    y1 = (s32)(((u32)y1 << 4) + (u32)D_001D3F40[0].y - 8);
    x2 = (s32)(((u32)x2 << 4) + (u32)D_001D3F40[0].x - 8);
    y2 = (s32)(((u32)y2 << 4) + (u32)D_001D3F40[0].y - 8);
    vertices[0] = (u64)x1 | ((u64)y1 << 16) | high;
    vertices[1] = (u64)x2 | ((u64)y1 << 16) | high;
    vertices[2] = (u64)x1 | ((u64)y2 << 16) | high;
    vertices[3] = (u64)x2 | ((u64)y2 << 16) | high;
    func_0044AA58(vertices, colors);
}
