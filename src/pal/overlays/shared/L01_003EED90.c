/* cflags: -fno-gcse */
#include "common.h"

extern void func_0046C6B0(u8 *);
extern void func_00474148(void *, s32, s32, f32);
extern void func_L00_00521468(u8 *);

// Update of a moby tied to an owner of class 0x18DF (vars[0]): frees it when the owner is gone
// or no longer points back at it, otherwise steps its animation states after the owner's state.
void func_L01_003EED90(u8 *moby) {
    u8 **vars;
    u8 *owner;

    if (moby == NULL) {
        return;
    }
    vars = *(u8 ***)(moby + 0xAC);
    if (vars == NULL) {
        return;
    }
    owner = vars[0];
    if (owner == NULL || *(s16 *)(owner + 0xBC) != 0x18DF || owner[0x20] == 0xFE || owner[0x20] == 0xFD ||
        *(u8 **)(*(u8 **)(owner + 0xAC) + 0x14) != moby) {
        func_0046C6B0(moby);
        return;
    }
    if (*(s32 *)(*(u8 **)(owner + 0xAC) + 0x24) == 0) {
        return;
    }
    switch (moby[0x20]) {
    case 0:
        if (moby[0x55] & 2) {
            if (moby[0x54] != 1) {
                func_00474148(moby, 1, 8, 0.0f);
            }
            moby[0x20] = 1;
            *(f32 *)(moby + 0x48) = 1.0f;
        }
        break;
    case 1:
        if (owner[0x20] == 2) {
            if (moby[0x54] != 3) {
                func_00474148(moby, 3, 8, 0.0f);
            }
            moby[0x20] = 3;
            *(f32 *)(moby + 0x48) = 1.0f;
        } else if (owner[0x20] == 8) {
            if (moby[0x54] != 2) {
                func_00474148(moby, 2, 8, 0.0f);
            }
            moby[0x20] = 2;
            *(f32 *)(moby + 0x48) = 1.0f;
        }
        break;
    case 2:
        if (moby[0x55] & 2) {
            func_0046C6B0(moby);
            return;
        }
        break;
    case 3:
        if (moby[0x55] & 2) {
            if (moby[0x54] != 4) {
                func_00474148(moby, 4, 8, 0.0f);
            }
            moby[0x20] = 4;
        }
        break;
    case 4:
        if (owner[0x20] >= 3 && owner[0x20] < 6) {
            if (moby[0x54] != 5) {
                func_00474148(moby, 5, 8, 0.0f);
            }
            moby[0x20] = 5;
        }
        break;
    case 5:
        if (moby[0x55] & 2) {
            *(f32 *)(moby + 0x48) = 0.0f;
        }
        if (vars[0][0x20] >= 6 && vars[0][0x20] < 8) {
            *(f32 *)(moby + 0x48) = 1.0f;
            if (moby[0x54] != 7) {
                func_00474148(moby, 7, 8, 0.0f);
            }
            moby[0x20] = 7;
        }
        break;
    case 6:
        break;
    case 7:
        if (!(moby[0x55] & 2)) {
            break;
        }
    default:
        if (moby[0x54] != 1) {
            func_00474148(moby, 1, 8, 0.0f);
        }
        moby[0x20] = 1;
        break;
    }
    func_L00_00521468(moby);
}
