/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_1AFD28[];
/* Stores the global buffer address; a null output returns 0x17. */
s32 func_01EA4EE8(s32 **arg0) {
    if (arg0 == NULL) return 0x17;
    *arg0 = D_1AFD28;
    return 0;
}
