#include "common.h"

s32 func_005F4610(void *, s32, s32);
s32 func_L00_006AC888(void *, s32, s32);
extern s32 D_0021E6B4;
typedef struct Type2 { u8 pad0[0x34]; u16 f34; u8 pad36[0x31]; u8 f67; } Type2;
typedef struct Type3 { u8 pad0[0x3C]; s32 f3C; } Type3;
typedef struct Type4 { u8 pad0[0x32]; u8 f32; } Type4;
typedef struct Type1 {
    u8 pad0[0x2B0]; Type2 *f2B0;
    u8 pad2B4[4];
    Type2 *f2B8; Type2 *f2BC;
    u8 pad2C0[0x28]; f32 f2E8;
    u8 pad2EC[0x20]; s32 f30C;
    u8 pad310[0x14]; Type3 *f324;
} Type1;
extern Type4 *D_0021DFF0;

// Pick an animation/state id for the owner's target object and apply it.
void func_L00_006F4038(Type1 *arg0) {
    Type2 *obj;
    Type2 *other;
    s32 id;
    s32 mode;
    u8 kind;

    if (arg0->f2E8 <= 0.0f) {
        return;
    }
    obj = arg0->f2B0;
    if (obj == NULL) {
        return;
    }
    kind = obj->f67;
    if (kind == 10 || kind == 7 || kind == 8) {
        return;
    }
    if (obj->f34 & 1) {
        return;
    }
    if (D_0021E6B4 == 1) {
        mode = arg0->f30C;
        id = (mode != 10) ? mode : -1;
        if (D_0021DFF0->f32 != 0) {
            if ((other = arg0->f2B8) != NULL || (other = arg0->f2BC, id = -1, other != NULL)) {
                id = func_L00_006AC888(other, mode, id);
            }
        }
        mode = arg0->f324->f3C;
        if (mode == 0) {
            func_005F4610(arg0->f2B0, 8, id);
        } else {
            func_005F4610(arg0->f2B0, mode, id);
        }
    } else {
        if (arg0->f2B8 != NULL || arg0->f2BC != NULL) {
            id = 2;
        } else {
            id = 10;
        }
        mode = arg0->f324->f3C;
        if (mode != 0) {
            func_005F4610(arg0->f2B0, mode, id);
        } else {
            func_005F4610(arg0->f2B0, 8, id);
        }
    }
}
