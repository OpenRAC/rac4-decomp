#include "common.h"

void func_00626D50(s32, s32, s32);
extern s32 D_0039C4A0[];

typedef struct { u8 pad0[0x2F10]; s32 f2F10; } Type1;

// Run func_00626D50 (2, 0, param) and clear the D_0039C4A0 entry indexed by
// the player's +0x2F10 word.
void func_L01_0046E7D8(s32 param, Type1 *player) {
    func_00626D50(2, 0, param);
    D_0039C4A0[player->f2F10] = 0;
}
