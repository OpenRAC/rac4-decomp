#include "common.h"
typedef struct Item {
    u8 disabled;
    u8 pad[3];
    const char *text;
    s32 data;
} Item;
typedef struct State {
    u8 pad[0x30];
    s32 count, remaining, unused;
    const Item *items;
    u8 tail[0x1C0];
} State;
extern State D_00307254[];
extern s32 func_00504F68(u32, s32), func_00505238(u32, const char *), func_00505328(u32, u32);
void func_004A0040(s32 slot, s32 count, const Item *items)
{
    s32 i;
    State *p = (State *)((u32)D_00307254 + ((u32)slot << 9));
    p->items = items;
    p->remaining = count;
    p->count = count;
    if (count > 0) {
        const Item *q = items;
        u32 b = 0x14000E + ((u32)slot << 6), a = 0x14000D + ((u32)slot << 6);
        s32 left = count;
        do {
            func_00504F68(a, 1);
            func_00504F68(b, 1);
            func_00505238(b, q->text);
            if (q->disabled)
                func_00505328(b, 0x80808080);
            else
                func_00505328(b, 0x80404040);
            q++;
            b += 2;
            left--;
            a += 2;
        } while (left);
    }
    for (i = count; i < 8; i++) {
        func_00504F68(0x14000D + (u32)i * 2 + ((u32)slot << 6), 0);
        func_00504F68(0x14000E + (u32)i * 2 + ((u32)slot << 6), 0);
    }
}
