#include "common.h"

typedef struct {
    u32 pad00;
    u32 flags;
    u8 pad08[8];
} Entry;

extern Entry D_00306E20[];

void func_0049B3A8(s32 index, u32 mask, s32 enable)
{
    Entry *entry = &D_00306E20[index];
    if (enable) {
        entry->flags |= mask;
    } else {
        entry->flags &= ~mask;
    }
}
