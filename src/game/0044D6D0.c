#include "common.h"

typedef struct State {
    u8 enabled;
    u8 unknown1[3];
    s32 index;
    s32 selected;
    s32 selector;
    u8 unknown10[8];
    u64 primary_key;
    u64 current;
    u64 current_secondary;
    u64 key30;
    u64 key38;
    u8 unknown40[8];
    u64 key48;
} State;
typedef struct Entry {
    u8 prefix[0x10];
    u64 value;
    u8 tail[8];
} Entry;
extern State D_00239640;
extern Entry D_003D7B40[];
extern u32 *D_00221F20;
void func_0044D6D0(void *unused, s32 id)
{
    if (D_00239640.enabled == 0) {
        if (id == 0)
            return;
        D_00221F20[0] = 0x30000002;
        D_00221F20[1] = (u32)&D_003D7B40[id];
        D_00221F20[2] = 0;
        D_00221F20[3] = 0x50000002;
        D_00221F20 += 4;
        return;
    }
    if (id == 0)
        return;
    if (D_00239640.selected != id && D_00239640.current == D_003D7B40[id].value) {
        D_00239640.selected = id;
        return;
    }
    if (D_00239640.current == D_003D7B40[id].value)
        return;
    D_00221F20[0] = 0x30000002;
    D_00221F20[1] = (u32)&D_003D7B40[id];
    D_00221F20[2] = 0;
    D_00221F20[3] = 0x50000002;
    D_00239640.selected = id;
    D_00239640.current = D_003D7B40[id].value;
    D_00221F20 += 4;
}
