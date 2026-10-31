#include "common.h"

extern u8 D_3094F8[];
extern void func_004AFDF8(void);
extern s32 func_00505B20(void);

// Claim the next free slot of D_3094F8 (stride 0x28) and mark it in use, then call func_004AFDF8.
void func_004AFC80(void) {
    s32 *ent;

    ent = (s32 *)(D_3094F8 + func_00505B20() * 0x28);
    func_004AFDF8();
    ent[0] = 1;
    ent[1] = 1;
}
