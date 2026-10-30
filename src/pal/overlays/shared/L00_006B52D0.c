#include "common.h"

extern f32 D_0021DE7C;

extern f32 func_00454328(f32, f32);
extern f32 func_00454158(f32);
extern s32 func_00454480(u32, u32, f32);

// When the player's object at +0x22F0 exists and the checks on +0x25CC, +0x2310, +0x2318 and bit 0
// of the object's +0x34 pass, advances the angle at +0x231C and stores a colour mixed by its
// sine (func_00454480) at +0x60 of the object.
void func_L00_006B52D0(u8 *arg0) {
    u8 *obj = *(u8 **)(arg0 + 0x22F0);

    if (obj != NULL && *(s32 *)(arg0 + 0x25CC) != 0x63 && ((obj[0x34] ^ 1) & 1) &&
        *(s32 *)(arg0 + 0x2310) >= 0x13 && *(s32 *)(arg0 + 0x2318) == 3) {
        *(f32 *)(arg0 + 0x231C) = func_00454328(*(f32 *)(arg0 + 0x231C),
                                                D_0021DE7C * 3.4906585f * *(f32 *)(arg0 + 0x25C4));
        *(s32 *)(obj + 0x60) = func_00454480(0xFFDFDFDF, 0xFF20205F,
                                             func_00454158(*(f32 *)(arg0 + 0x231C)) * 0.5f + 0.5f);
    }
}
