#include "common.h"

extern s8 D_0030F488[];
void func_006390E0(void);

// Run func_006390E0, then clear the byte at D_0030F488.
void func_L00_006390B8(void) {
    func_006390E0();
    D_0030F488[0] = 0;
}
