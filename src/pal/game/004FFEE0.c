#include "common.h"
typedef struct {
    u8 unknown0[0x18];
    const u8 *primary[6];
    const u8 *secondary[6];
    u32 count[6];
    f32 scale;
} Resource;
u8 D_00220B38[6] = {
    2, 3, 2, 1, 1, 1};
extern void func_00503540(const void *input, u32 *kind, u32 *count);
const u8 *func_004FFEE0(Resource *resource, const u8 *input)
{
    u32 kind = 0xFFFF;
    u32 count = 0;
    const u8 *end = 0;
    func_00503540(input, &kind, &count);
    input += 4;
    kind -= 1u;
    if (kind < 6u && count) {
        resource->scale = *(const f32 *)input;
        resource->primary[kind] = input + 4;
        resource->secondary[kind] = (const u8 *)((const u32 *)input + count) + 4;
        resource->count[kind] = count;
        if (kind == 3u)
            end = (const u8 *)((u32)resource->secondary[3] + D_00220B38[3] * 4u);
        else if (kind == 4u)
            end = (const u8 *)((u32)resource->primary[4] + count * D_00220B38[4] * 4u);
        else
            end = (const u8 *)((u32)resource->secondary[kind] + count * D_00220B38[kind] * 4u);
    }
    return end;
}
