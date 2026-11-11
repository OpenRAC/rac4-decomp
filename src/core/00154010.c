/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_0016F8F8[];

/* True when the halfword at 0x4 is one of the eight bytes of the table. */
s32 func_00154010(void *arg0) {
    u16 value = *(u16 *)((u8 *)arg0 + 4);
    u32 i;

    for (i = 0; i < 8; i++) {
        if (value == D_0016F8F8[i]) {
            return 1;
        }
    }
    return 0;
}
