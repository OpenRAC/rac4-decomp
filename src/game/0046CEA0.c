#include "common.h"

typedef struct {
    u8 pad[0xB];
    u8 dimensions;
    u8 padC[0x14];
    u8 *data;
} Data;
typedef struct {
    u8 pad[0x24];
    Data *data;
} Object;
typedef struct {
    u32 *packet;
    u32 taggedObject;
} Entry;
extern Entry *D_0022144C;
extern Entry D_00265D60[];
extern u8 *D_00221E20;
extern u8 D_003D82F0[], D_003DA6B0[];
extern void func_004537D0(void *, const void *, s32);
void func_0046CEA0(void)
{
    u32 *header;
    Entry *entry;
    if (D_0022144C == D_00265D60)
        return;
    header = (u32 *)D_00221E20;
    D_00221E20 = (u8 *)(header + 4);
    for (entry = D_00265D60; entry < D_0022144C; entry++) {
        u32 *packet = entry->packet;
        u32 value = entry->taggedObject;
        Object *object;
        Data *data;
        s32 width, height, index;
        u8 *base;
        s32 i;
        packet[0] = 0x20000000;
        index = value & 15;
        object = (Object *)(value & ~15);
        packet[1] = (u32)D_00221E20;
        packet[3] = 0x11000000;
        data = object->data;
        height = data->dimensions >> 4;
        width = data->dimensions & 15;
        base = data->data - ((width * height) << 10) - 16;
        for (i = 0; i < height; i++) {
            s16 value = ((s16 *)base)[i];
            func_004537D0(D_00221E20, D_003D82F0, 0x70);
            *(s16 *)(D_00221E20 + 0x24) = value;
            *(u8 **)(D_00221E20 + 0x64) = base + (index << 10) + 16 + ((i * width) << 10);
            D_00221E20 = D_00221E20 + 0x70;
        }
        ((u32 *)D_00221E20)[0] = 0x30000003;
        ((u32 *)D_00221E20)[1] = (u32)D_003DA6B0;
        ((u32 *)D_00221E20)[2] = 0;
        ((u32 *)D_00221E20)[3] = 0x50000003;
        D_00221E20 += 0x10;
        ((u32 *)D_00221E20)[0] = 0x20000000;
        ((u32 *)D_00221E20)[1] = (u32)(packet + 4);
        ((u32 *)D_00221E20)[2] = 0;
        ((u32 *)D_00221E20)[3] = 0;
        D_00221E20 = D_00221E20 + 0x10;
    }
    header[0] = 0x20000000;
    header[1] = (u32)D_00221E20;
    header[2] = 0;
    header[3] = 0;
}
