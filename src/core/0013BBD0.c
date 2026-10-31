/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_0013B8C8(s32 arg0, s32 arg1, void *out);
extern s32 D_001AF010[][4][7];

/* Returns byte 0x71 of the record func_0013B8C8 yields, or 0 when the word at 0x10 is clear. */
u8 func_0013BBD0(s32 arg0, s32 arg1) {
    if (D_001AF010[arg0][arg1][4] == 0) {
        return 0;
    }
    return *((u8 *)func_0013B8C8(arg0, arg1, 0) + 0x71);
}
