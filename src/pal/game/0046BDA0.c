#include "common.h"
typedef struct Hero {
    u8 pad[0x2F10];
    s32 slot;
} Hero;
typedef struct Row {
    u8 pad[0x100];
    s32 index, count;
    u8 tail[8];
} Row;
extern s32 D_0021EE54, D_0021EE58;
extern u8 D_00242180[];
extern Hero *func_00511CC0(s32);
extern s32 func_0046BE78(void **, Hero *, Row *);
void *func_0046BDA0(Hero *h)
{
    Hero *other = 0;
    void *result;
    if (D_0021EE54 == 0 && D_0021EE58 == 1)
        other = func_00511CC0(!h->slot);
    if (other && func_0046BE78(&result, other, 0))
        return result;
    if (func_0046BE78(&result, other, (Row *)((u32)D_00242180 + (u32)h->slot * 0x110)))
        return result;
    {
        Row *row = (Row *)((u32)D_00242180 + (u32)h->slot * 0x110);
        if (row->count > 0)
            return (void *)((u32)row + ((u32)row->index << 5));
    }
    return 0;
}
