#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *func_0046C1F0(s32, s32);
extern void func_0046D258(u8 *, s32, u8 *);
extern void func_00474368(u8 *, s32, s32);
extern void func_0046D160(u8 *, s32, u128 *);
extern void func_00477680(u128 *, u8 *);

// Creates a moby of class 0x200F with 0x10 bytes of data attached to owner: stores joint, bone
// and flags (bit 3 sets +0xA), scales it to 0.4 * scale relative to the owner's own scale (1.0 when
// the owner is gone, state 0xFE/0xFD), and takes the bone's matrix from func_0046D160. Returns 1,
// or 0 when no moby could be made or there is no owner.
s32 func_L01_00432918(u8 *owner, s32 joint, s32 bone, s32 flags, f32 scale) {
    u128 mtx[4];
    u8 pos[0x10];
    u8 *moby = func_0046C1F0(0x200F, 0x10);
    u8 *v1;
    u8 *v2;
    u8 *o;
    f32 f;
    u128 *m;

    if (moby == NULL) {
        return 0;
    }
    if (owner == NULL) {
        return 0;
    }
    v1 = *(u8 **)(moby + 0xAC);
    if (flags & 8) {
        v1[0xA] = 1;
    } else {
        v1[0xA] = 0;
    }
    func_0046D258(owner, v1[8], pos);
    v2 = *(u8 **)(moby + 0xAC);
    *(u8 **)(moby + 0xB8) = owner;
    moby[0x30] = 0xFF;
    *(s16 *)(moby + 0x32) = 0xFF;
    v2[8] = joint;
    o = *(u8 **)(moby + 0xB8);
    if (o != NULL && o[0x20] != 0xFE && o[0x20] != 0xFD) {
        f = *(f32 *)(o + 0x70) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
    } else {
        f = 1.0f;
    }
    *(f32 *)(moby + 0x70) = scale * f * 0.4f;
    *(s32 *)(v2 + 0) = flags;
    func_00474368(moby, 0, -1);
    *(s16 *)(v2 + 4) = 0x25;
    v1[9] = bone;
    func_0046D160(*(u8 **)(moby + 0xB8), (s8)bone, mtx);
    func_00477680(mtx, moby + 0xF0);
    m = (u128 *)(moby + 0xC0);
    m[0] = mtx[0];
    m[1] = mtx[1];
    m[2] = mtx[2];
    return 1;
}
