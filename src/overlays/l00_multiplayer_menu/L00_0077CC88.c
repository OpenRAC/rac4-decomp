#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern u8 D_172160[];

// When arg0's 0x18 field is clear, stores its 0x1C field and a scaled timestamp into D_172160.
void func_L00_0077CC88(u8 *arg0) {
    u8 *g;

    if (*(s32 *)(arg0 + 0x18) == 0) {
        g = D_172160;
        *(s32 *)(g + 0x130) = *(s32 *)(arg0 + 0x1C);
        *(u64 *)(g + 0x138) = func_0012FEB0(func_0012E370(), 0x24000);
    }
}
