#include "common.h"

s32 D_00221D40 = 0;
extern s32 func_L00_0066D220(s32, s32, void *);
extern void func_L10_004AAC28(void *);

// Latches the pending flag into the object's state, then runs the two update calls while +0x31 is set and bit 2 of +0xBE is set.
void func_L10_004AB058(u8 *o) {
    s32 *child;
    s32 render;
    u32 flags;

    if (D_00221D40 != 0) {
        child = *(s32 **)(o + 0x24);
        flags = *(u16 *)(o + 0x34);
        render = child[4];
        o[0x31] = 1;
        *(s32 *)(o + 0x98) = render;
        *(u16 *)(o + 0x34) = flags & 0xFFFE;
        D_00221D40 = 0;
    }
    if (o[0x31] != 0 && (o[0xBE] & 4)) {
        func_L10_004AAC28(o);
        func_L00_0066D220(0, 0, o);
        o[0x31] = 0;
        *(s32 *)(o + 0x98) = 0;
        *(u16 *)(o + 0x34) |= 1;
    }
}
