#include "common.h"

extern s32 D_002215D8;

extern void func_00453F30(void *, const void *, u32);
extern void *func_0048C2D0(u32, u8 **, const u8 *);

s32 func_0048C2F8(const u8 *arg0, u8 **arg1, const u8 *arg2) {
    s32 i;
    s32 offset;

    func_00453F30((void *)(D_002215D8 + 0x300C), arg0, 4);
    arg0 += 4;
    *(void **)(D_002215D8 + 0x3010) = func_0048C2D0(*(s32 *)(D_002215D8 + 0x300C) * 0xC, arg1, arg2);
    if (*(s32 *)(D_002215D8 + 0x3010) == 0) {
        return 1;
    }
    if (*(s32 *)(D_002215D8 + 0x300C) <= 0) {
        return 0;
    }
    i = 0;
    offset = 0;
    do {
        if (*(s32 *)(D_002215D8 + 0x3000) >= 2) {
            func_00453F30((void *)(*(u32 *)(D_002215D8 + 0x3010) + offset), arg0, 0xC);
            arg0 += 0xC;
        } else {
            func_00453F30((void *)(*(u32 *)(D_002215D8 + 0x3010) + offset), arg0, 8);
            arg0 += 8;
            *(s16 *)(offset + *(s32 *)(D_002215D8 + 0x3010) + 8) = 0;
        }
        i++;
        offset += 0xC;
    } while (i < *(s32 *)(D_002215D8 + 0x300C));
    return 0;
}
