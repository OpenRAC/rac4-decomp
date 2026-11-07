/* Not matching yet: BYTES 2/364 (tools/try_func.py func_004F3220 --diff). Not part of the build. */
#include "common.h"

extern void func_00158568(void);
extern void func_004F2530(const void *request, s32 *result, u32 destination, u32 size);
extern u8 D_001D2200[];
extern u8 *D_0023AB20[];
extern s32 D_00328890[];
extern s32 D_003288D0[];
extern s32 D_00328910[];

void func_004F3220(s32 count, s32 *list)
{
    s32 order[16];
    u8 *base = D_0023AB20[0];
    u8 *data = base + *(s32 *)(base + 8);
    s32 i;
    u32 dest;
    s32 *tbl;
    u8 *ents;
    u8 *hdr;

    for (i = 15; i >= 0; i--) {
        D_003288D0[15 - i] = -1;
        D_00328910[15 - i] = -1;
    }
    if (list == 0) {
        for (i = 0; i < count; i++) {
            order[i] = i;
        }
        list = order;
    }
    dest = 0x5040;
    hdr = D_001D2200;
    *(u32 *)(hdr + 0x29C) = 0xFFFFFFFF;
    i = 0;
    if (count > 0) {
    tbl = (s32 *)(base + 0xB4);
    ents = data + 0x18;
    do {
        s32 idx = list[i];
        s32 off;
        s32 size;
        D_003288D0[idx] = i;
        off = tbl[idx];
        size = *(s32 *)(ents + off + 0x2C);
        func_004F2530(data + off, &D_00328890[i], dest, size);
        dest += size;
        i++;
    } while (i < count);
    }
    func_00158568();
}
