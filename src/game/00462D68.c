#include "common.h"

typedef struct {
    s32 *data;
    s32 packed_count;
    s32 reserved[2];
} Group;
extern void func_00462608(void *, const void *, s32, s32, s32, s32, s32);
extern void func_00462910(void *, s32, s32, s32, s32, s32);
void func_00462D68(Group *groups, const u8 *palette, const u8 *mapping, s32 count)
{
    s32 i, j, group_count, offset, index;
    s32 *entry;
    Group *group = groups;
    Group *next;
    for (i = 0; i < count; i++) {
        next = group + 1;
        group_count = group->packed_count >> 16;
        offset = group->packed_count & 0xFFFF;
        group->packed_count = offset;
        entry = (s32 *)((u32)group->data + (u32)((offset - group_count) * 16));
        for (j = 0; j < group_count; j += 4) {
            index = entry[8];
            if (index >= 0)
                index = mapping[index];
            if (palette) {
                func_00462608(entry, (const void *)((u32)palette + (u32)(index * 16)),
                              entry[0], entry[1], entry[4], entry[5], index);
            } else {
                func_00462910(entry, entry[0], entry[1], entry[4], entry[5], index);
            }
            entry += 16;
        }
        group = next;
    }
}
