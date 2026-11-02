#include "common.h"

extern void func_005B0038(void *, void *, s32);
extern s32 D_002221D4;
extern void D_006B0B98(void);

// Register the callback once per player, guarded by the +0x25C9 flag.
void func_L00_006AE158(u8 *player) {
    if (player[0x25C9] == 0) {
        player[0x25C9] = 1;
        func_005B0038(&D_002221D4, D_006B0B98, *(s32 *)(player + 0x2EF0));
    }
}
