/* cflags: -mno-split-addresses */
#include "common.h"
extern void func_01F07D54(void **a0);
extern u8 D_00170F10[];

// Calls func_01F07D54 with the pointer, then stores the address of D_00170F10 through it.
void func_01F07F20(void **a0) {
    func_01F07D54(a0);
    *a0 = D_00170F10;
}
