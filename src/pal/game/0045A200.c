/* cflags: -G0 */
#include "common.h"

extern s32 D_002397F4;

/* Copy the caller's 32-bit argument to the PAL global at 0x002397F4. */
void func_0045A200(s32 value) {
    D_002397F4 = value;
}
