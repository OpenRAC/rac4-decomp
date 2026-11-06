/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00500CE0();                            /* extern */

s32 func_L00_004FFBC0(void *arg0) {
    if (arg0 != NULL) {
        if (!(func_L00_00500CE0() & 0x3000) || ((*(s64 *)((u8 *)(arg0) + 0x100)) & 0x40000)) {
            return (*(s32 (**)(void *))((u8 *)((*(void **)((u8 *)(arg0) + 8))) + 0x24))(arg0);
        }
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 1;
    }
    return 1;
}
