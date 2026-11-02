/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern u8 D_00220A30;
extern s32 D_00220A34;
/* Return 0x40 when the global byte flag is nonzero; otherwise the other global. */

s32 func_L00_007098C0(void) {
    return (D_00220A30 != 0) ? 0x40 : D_00220A34;
}
