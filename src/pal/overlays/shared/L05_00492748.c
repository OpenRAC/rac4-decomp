#include "common.h"

extern void func_L01_005A5EB0(u8 *);
extern s32 func_L01_005A4520(u8 *, u32, u32, f32);
extern void func_L01_0056F988(u8 *);
extern void func_L01_005713D8(u8 *);
extern void func_L01_005ACCA0(u8 *);
extern void func_L01_0058CDE8(u8 *);

// Unless +0x69 is 2: walks the list at vars+0x244 (linked through +0x2A4 of each member's data),
// removes members whose flags at +0x30 match and whose +0x98 is 0 (counting them down at +0x240)
// and colours the rest with func_L01_005A4520. When the list is empty, finishes the moby (hidden
// with state 0xFD when +0x1A8 is set) and returns 1; otherwise returns 0.
s32 func_L05_00492748(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0xAC);
    u8 **link;
    u8 *m;
    s32 color;

    if (moby[0x69] == 2) {
        return 0;
    }
    link = (u8 **)(vars + 0x244);
    func_L01_005A5EB0(moby);
    m = *(u8 **)(vars + 0x244);
    color = func_L01_005A4520(vars + 0x268, 0xFF202020, 0xFFC0C0C0, 0.37696657f);
    while (m != NULL) {
        u8 *mv = *(u8 **)(m + 0xAC);

        if ((*(u64 *)(m + 0x30) & (0x8208ULL << 29)) == (0x8200ULL << 23) && *(s32 *)(m + 0x98) == 0) {
            *link = *(u8 **)(mv + 0x2A4);
            (*(s32 *)(vars + 0x240))--;
        } else {
            *(s32 *)(m + 0x60) = color;
            link = (u8 **)(mv + 0x2A4);
        }
        m = *link;
    }
    *(u16 *)(moby + 0x34) &= 0xFEFF;
    if (*(u8 **)(vars + 0x244) == NULL) {
        func_L01_0056F988(moby);
        func_L01_005713D8(moby);
        func_L01_005ACCA0(moby);
        if (vars[0x1A8] == 0) {
            func_L01_0058CDE8(moby);
        } else {
            moby[0x20] = 0xFD;
            moby[0x31] = 0;
            *(u16 *)(moby + 0x34) |= 3;
        }
        *(s16 *)(vars + 0x26C) = -1;
        return 1;
    }
    return 0;
}
