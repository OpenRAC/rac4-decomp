/* cflags: -mno-split-addresses */
#include "common.h"
extern void func_01F07D54(void **a0);
extern char D_00170ED0[];

// Calls func_01F07D54 on a0, then stores the address of D_00170ED0 through a0.
void func_01F07D98(void **a0) {
    func_01F07D54(a0);
    *a0 = &D_00170ED0;
}
