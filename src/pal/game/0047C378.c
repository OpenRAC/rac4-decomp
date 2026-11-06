#include "common.h"

typedef unsigned int Quadword __attribute__((mode(TI)));
extern char *D_00221478;
extern char *D_0026F740[];
extern s32 func_004FF388(Quadword position, const void *sphere);
extern s32 func_00472DF8(const Quadword *position, s32 shape, void *output);
extern s32 func_00478738(Quadword position, s32 shape, void *output);
extern s32 func_00478640(Quadword position, s32 shape, void *output);
extern s32 func_004749A0(const Quadword *position, const void *vertices, s32 count);

/* Tests a point against each geometry list belonging to a region. */
s32 func_0047C378(Quadword position, s32 index)
{
    char *region;
    u32 offset;
    s32 i;
    if (index < 0 || index >= *(s32 *)D_00221478)
        return 0;
    offset = (u32)index * 0x30u + 0x20u;
    if (!func_004FF388(position, (void *)((u32)D_00221478 + offset)))
        return 0;
    region = (char *)((u32)D_00221478 + offset);
    for (i = 0; i < *(s16 *)(region + 0x12); i++) {
        if (func_00472DF8(&position, (*(s32 **)(region + 0x20))[i], 0))
            return 1;
    }
    for (i = 0; i < *(s16 *)(region + 0x14); i++) {
        if (func_00478738(position, (*(s32 **)(region + 0x24))[i], 0))
            return 1;
    }
    for (i = 0; i < *(s16 *)(region + 0x16); i++) {
        if (func_00478640(position, (*(s32 **)(region + 0x28))[i], 0))
            return 1;
    }
    for (i = 0; i < *(s16 *)(region + 0x10); i++) {
        s32 id = (*(s32 **)(region + 0x1C))[i];
        char *polygon = *(char **)((u32)D_0026F740 + ((u32)id << 2));
        if (func_004749A0(&position, polygon + 0x10, *(s32 *)polygon))
            return 1;
    }
    return 0;
}
