#include "common.h"

extern s32 func_004600C0(s32, s32);
extern u8 D_0021DD52;
extern u8 D_0021DD53;
extern u8 D_0021DD54;

// When none of the three flags is set, runs func_004600C0(0x8000, 7) and sets the first flag.
void func_004610A8(void) {
    if (D_0021DD52 == 0) {
        if (D_0021DD53 == 0 && D_0021DD54 == 0) {
            func_004600C0(0x8000, 7);
            D_0021DD52 = 1;
        }
    }
}
