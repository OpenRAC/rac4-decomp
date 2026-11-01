#include "common.h"

extern void func_0044B920(const f32 *vertices, const u32 *colors, u64 texture);

/* Draw four vertices with one color, preserving the caller's texture argument. */
void func_0044BD28(const f32 *vertices, u32 color, u64 texture)
{
    u32 colors[4] = {color, color, color, color};
    func_0044B920(vertices, colors, texture);
}
