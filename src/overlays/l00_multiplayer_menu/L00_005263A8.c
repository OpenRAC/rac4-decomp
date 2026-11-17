/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_005208E8(s32, s32, s32, s32, void *, s32);

// Read the record at arg0->f4 and return its count, less one when the byte at +0xC is zero.
s32 func_L00_005263A8(s32 *arg0) {
    s32 sp0;
    s32 *sp4;
    s32 ret;
    u8 *byte;

    ret = 0;
    sp4 = 0;
    sp0 = 0;
    func_L00_005208E8(arg0[1], 0x10, 0x10, (s32)&sp0, &sp4, 0);
    if (sp4 != 0) {
        byte = (u8 *)sp4[3];
        ret = sp4[4];
        if (*byte == 0) {
            ret = ret - 1;
        }
    }
    return ret;
}
