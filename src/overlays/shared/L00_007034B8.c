#include "common.h"

extern void func_L00_005BCBF0(void *dst, void *src, s32 n);
extern void func_L00_006BD738(u8 *player, u8 *input);
extern u8 *D_00343E78[];

s32 func_L00_007034B8(s32 unused0, s32 unused1, s32 unused2, void *data) {
    u8 buffer[0x10];
    u8 *obj;
    s64 a1;
    s32 b;
    u8 *tmp;

    func_L00_005BCBF0(buffer, data, 0x10);
    obj = D_00343E78[buffer[0xD] & 0xF];
    a1 = 0;
    if (obj == NULL)
        goto check;
    if (*(s32 *)(obj + 0x25CC) == 0x9B)
        goto check;
    tmp = *(u8 **)(obj + 0x2F28);
    if (tmp == NULL)
        goto check;
    b = *(u32 *)(tmp + 4) != 0;
    a1 = b;
check:
    if ((a1 & 0xFF) != 0)
        func_L00_006BD738(obj, buffer);
    return 0x10;
}
