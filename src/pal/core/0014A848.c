#include "common.h"
void func_0014A848(const f32 *values, s32 first, s32 end, s32 capacity, s32 *positions, s32 *count_out)
{
    s32 index = (s32)((u32)first + 1u);
    s32 limit = (s32)((u32)end - 1u);
    s32 found = 0;
    if (index < limit) {
        u32 cursor = (u32)index * 4u + (u32)values;
        do {
            f32 center = *(const f32 *)cursor;
            if (*(const f32 *)(cursor - 4u) <= center && *(const f32 *)(cursor + 4u) < center) {
                *positions++ = index;
                cursor += 4u;
                found++;
                index = (s32)((u32)index + 1u);
                if (found == capacity)
                    break;
            }
            index = (s32)((u32)index + 1u);
            cursor += 4u;
        } while (index < limit);
    }
    *count_out = found;
}
