/* cflags: -G0 */
#include "common.h"

extern s32 D_0022B300;

/* Clear the 32-bit PAL global at 0x0022B300. */
void func_0043DF40(void) {
    D_0022B300 = 0;
}
