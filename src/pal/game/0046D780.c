#include "common.h"

/* Control-flow reference: OpenRAC/OpenRAC 73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde,
 * games/rac3/ntsc/src/frontbin/3BDAC0.c:func_003BDEA8.
 * Reconstructed against RAC4 PAL retail; all address targets audited. */
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
extern Entry *D_0022154C;
extern Entry D_00265E60[];
extern u8 *D_00221F20;
extern u8 D_003D8350[], D_003DA6F0[];
extern void func_00453FE8(void *, const void *, s32);
void func_0046D780(void)
{
    u32 *header;
    Entry *entry;
    if (D_0022154C == D_00265E60)
        return;
    header = (u32 *)D_00221F20;
    D_00221F20 = (u8 *)(header + 4);
    for (entry = D_00265E60; entry < D_0022154C; entry++) {
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
        packet[1] = (u32)D_00221F20;
        packet[3] = 0x11000000;
        data = object->data;
        height = data->dimensions >> 4;
        width = data->dimensions & 15;
        base = data->data - ((width * height) << 10) - 16;
        for (i = 0; i < height; i++) {
            s16 value = ((s16 *)base)[i];
            func_00453FE8(D_00221F20, D_003D8350, 0x70);
            *(s16 *)(D_00221F20 + 0x24) = value;
            *(u8 **)(D_00221F20 + 0x64) = base + (index << 10) + 16 + ((i * width) << 10);
            D_00221F20 = D_00221F20 + 0x70;
        }
        ((u32 *)D_00221F20)[0] = 0x30000003;
        ((u32 *)D_00221F20)[1] = (u32)D_003DA6F0;
        ((u32 *)D_00221F20)[2] = 0;
        ((u32 *)D_00221F20)[3] = 0x50000003;
        D_00221F20 += 0x10;
        ((u32 *)D_00221F20)[0] = 0x20000000;
        ((u32 *)D_00221F20)[1] = (u32)(packet + 4);
        ((u32 *)D_00221F20)[2] = 0;
        ((u32 *)D_00221F20)[3] = 0;
        D_00221F20 = D_00221F20 + 0x10;
    }
    header[0] = 0x20000000;
    header[1] = (u32)D_00221F20;
    header[2] = 0;
    header[3] = 0;
}
