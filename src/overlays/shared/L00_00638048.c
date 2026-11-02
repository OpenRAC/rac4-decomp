#include "common.h"

extern s8 D_0030F3B8[];
void func_00638110(void);

// Run func_00638110, then clear the byte at D_0030F3B8.
void func_L00_00638048(void) {
    func_00638110();
    D_0030F3B8[0] = 0;
}
