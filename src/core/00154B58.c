/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001BCC28[];
extern s32 func_00126B30(s32);
u32 func_00154B58(void) {
    u8 *s = D_001BCC28;
    if (*(s32 *)(s + 0x30) == 0) {
        return 0x80000000;
    }
    if (func_00126B30(*(s32 *)(s + 0x30)) == *(s32 *)(s + 0x30)) {
        return 0;
    }
    return 0x80000000;
}
