#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 D_0021E734;
extern s32 D_0021E738;
extern s32 D_0021DE98;
extern s32 D_0021EAD8;

extern u8 *func_0046C1F0(s32, s32);
extern void func_00470990(u8 *, s32, s32, s32);
extern f32 func_00472EB8(f32, f32);
extern void func_00470FD0(u8 *);

// Spawns a moby of class 0x7A with 0x80 bytes of data at pos (not in the cases checked through
// D_0021E734/D_0021E738 and D_0021DE98/D_0021EAD8): grey colour, alpha 0x80, dir, two random spins
// between 0.12566371 and 0.25132743, time at +0x18/+0x1A, and mode (2 becomes 1 with +0x20 set;
// mode 0 also scales it by 0.5..0.75). Returns the moby or NULL.
u8 *func_L00_00569100(u128 *pos, u128 *dir, s32 time, s32 mode, s32 bit, s32 arg5) {
    u8 *moby;
    u8 *vars;

    if (D_0021E734 == 0 && D_0021E738 == 1) {
        return NULL;
    }
    if ((D_0021DE98 == 1 || D_0021DE98 == 0x15) && (D_0021EAD8 == 0x10 || D_0021EAD8 == 0x19)) {
        return NULL;
    }
    moby = func_0046C1F0(0x7A, 0x80);
    if (moby == NULL) {
        return NULL;
    }
    vars = *(u8 **)(moby + 0xAC);
    moby[0x30] = 0xFF;
    *(s16 *)(moby + 0x32) = 0xFF;
    moby[0x31] = 1;
    moby[0x23] = 0x80;
    *(s32 *)(vars + 0x24) = arg5;
    func_00470990(moby, 0x7F, 0x7F, 0x7F);
    *(u128 *)(moby + 0x10) = *pos;
    *(u128 *)(vars + 0) = *dir;
    *(s16 *)(vars + 0x28) = 0;
    *(f32 *)(vars + 0x10) = func_00472EB8(0.12566371f, 0.25132743f);
    *(f32 *)(vars + 0x14) = func_00472EB8(0.12566371f, 0.25132743f);
    *(s16 *)(vars + 0x18) = time;
    *(s16 *)(vars + 0x1A) = time;
    if (mode == 2) {
        mode = 1;
        *(s32 *)(vars + 0x20) = 1;
    }
    if (mode == 0) {
        *(f32 *)(moby + 0x70) *= func_00472EB8(0.5f, 0.75f);
    }
    *(f32 *)(vars + 0x1C) = *(f32 *)(moby + 0x70);
    moby[0x67] = mode | (bit << 1);
    func_00470FD0(moby);
    return moby;
}
