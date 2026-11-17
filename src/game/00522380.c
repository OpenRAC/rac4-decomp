#include "common.h"

extern s32 func_0048F878(s32, s32, s32, s32);
extern s32 func_004908D0(s32, s32);
extern s32 func_00521078(void *p);
extern s32 func_005210B0(void *p);

/* Check and trigger an action on the object when its state allows it. */
s32 func_00522380(u8 *p)
{
    if (*(s16 *)(p + 0x3BA) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x25CC) == 0xE) {
        return 0;
    }
    func_005210B0(p);
    func_00521078(p);
    func_004908D0(8, *(s32 *)(p + 0x2F10));
    if (*(s32 *)(p + 0x370) >= 7 && func_0048F878(func_004908D0(0x40, *(s32 *)(p + 0x2F10)), 9, 0, *(s32 *)(p + 0x2F00)) != 0) {
        ((s32 (*)(void *, s32, s32, s32, s32))(*(void ***)(p + 0x14))[0x3C / 4])(p, 7, 1, 0, 1);
        return 1;
    }
    return 0;
}
