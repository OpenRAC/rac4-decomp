#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *func_0046C1F0(s32, s32);
extern f32 func_00472EB8(f32, f32);
extern void func_00474368(u8 *, s32, s32);

// Creates a moby of class 0x262B with 0xAA0 bytes of data that follows owner: it takes the
// position and matrix kept in the owner's data, the word at +0x40 and the byte at +0x45, a random
// angle between -pi and pi, and arg1; arg1 0 sets +0xF7, otherwise +0xA98 = 15. Returns NULL when
// there is no moby or no owner.
u8 *func_L01_004770E0(u8 *owner, s32 arg1) {
    u8 *moby = func_0046C1F0(0x262B, 0xAA0);
    u8 *src;
    u8 *vars;
    u128 *m;

    if (moby == NULL) {
        return NULL;
    }
    if (owner == NULL) {
        return NULL;
    }
    src = *(u8 **)(owner + 0xAC);
    *(u8 **)(moby + 0xB8) = owner;
    m = (u128 *)(moby + 0xC0);
    moby[0x30] = 0xFF;
    *(s16 *)(moby + 0x32) = 0xFF;
    *(u16 *)(moby + 0x34) |= 0x100;
    moby[0x31] = 1;
    moby[0x67] = 0;
    vars = *(u8 **)(moby + 0xAC);
    *(u128 *)(moby + 0x10) = *(u128 *)(src + 0x30);
    m[0] = ((u128 *)src)[0];
    m[1] = ((u128 *)src)[1];
    m[2] = ((u128 *)src)[2];
    *(s32 *)(vars + 0xF0) = *(s32 *)(src + 0x40);
    vars[0xF4] = 0xC;
    vars[0xF6] = 0xC;
    vars[0xF5] = src[0x45];
    *(f32 *)(vars + 0xF8) = func_00472EB8(-3.1415927f, 3.1415927f);
    *(s32 *)(vars + 0xFC) = arg1;
    if (arg1 == 0) {
        vars[0xF7] = 1;
    } else {
        *(s32 *)(vars + 0xA98) = 0xF;
    }
    func_00474368(moby, 0, -1);
    return moby;
}
