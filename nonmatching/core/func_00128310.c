/* Not matching yet: BYTES 11/56 (@ee29, MMIO SIO poll; excluded by policy) (tools/try_func.py func_00128310 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

void func_00128310(s32 c) {
    while (*(volatile u32 *)0x1000F130 & 0x8000) {
    }
    *(volatile u8 *)0x1000F180 = c;
}
