/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_004CA1D0(int arg0, int arg1);
extern void func_004CA850(void);
extern u8 D_0021EE18[];

/* Starts action mode 6 when arg0 is set, mode 0x13 when the flag is set, otherwise opens the pause menu. */
void func_004CAFE0(int arg0) {
    if (arg0 != 0) {
        func_004CA1D0(6, 0);
    } else if (D_0021EE18[0] != 0) {
        func_004CA1D0(0x13, 0);
    } else {
        func_004CA850();
    }
}
