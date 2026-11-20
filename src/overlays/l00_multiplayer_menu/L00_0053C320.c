/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0012B5C8(s32 fd);

s32 func_L00_0053C320(u8 *arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (*(s32 *)(arg0 + 0x10) != 0) {
        if (*(s32 *)(arg0 + 0xC) != 0) {
            func_0012B5C8(*(s32 *)(arg0 + 0x1C));
        }
        *(s32 *)(arg0 + 0xC) = 0;
        *(s32 *)(arg0 + 0x14) = 0;
    }
    return 1;
}
