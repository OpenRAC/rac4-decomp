/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_L00_007081D8(void);
extern s32 func_L00_007647B0(s32 identifier);
extern s32 *D_00220D14[];
s32 D_002213D4 = 0;

// Sets a state value, notifies and clears a flag.
s32 func_L00_00752D48(void) {
    func_L00_007647B0(0x1D);
    D_00220D14[0][0x118 / 4] = 0x1F;
    func_L00_007081D8();
    D_002213D4 = 0;
    return 1;
}
