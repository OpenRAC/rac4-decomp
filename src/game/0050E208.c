/* cflags: -G0 */
#include "common.h"

s32 func_0050E208(u8 *arg0) {
    s32 kind;
    u8 *owner;
    if (*(u16 *)(arg0 + 0x50) != 0) {
        owner = *(u8 **)(arg0 + 0x58);
        if ((owner != NULL) && ((kind = *(s32 *)owner, ((kind ^ 1) == 0)) || ((kind ^ 8) == 0))) {
            (*(s32 (**)(u8 *, s32))(*(u8 **)(owner + 4) + 8))(owner, *(u16 *)(arg0 + 0x50) - 1);
        }
    }
    return 0;
}
