/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00535D48(u8 **, s32 *, s32, s32);

s32 func_L00_00535C18(u8 **pp, s32 arg1, s32 *tagOut, s32 *classOut, long remain) {
    u8 *p;
    s32 n;
    s32 cons;
    s32 cls;
    s32 low;
    s32 tag;
    long acc;

    p = *pp;
    if (remain == 0) goto fail;
    cons = *p & 0x20;
    cls = *p & 0xC0;
    low = *p & 0x1F;
    if (low == 0x1F) {
        p++;
        if (--remain == 0) goto fail;
        acc = 0;
        while (*p & 0x80) {
            acc <<= 7;
            acc |= *(p++) & 0x7F;
            if (--remain == 0) goto fail;
        }
        acc <<= 7;
        acc |= *(p++) & 0x7F;
        tag = (s32)acc;
    } else {
        tag = low;
        p++;
        if (--remain == 0) goto fail;
    }
    *tagOut = tag;
    *classOut = cls;
    if (!func_L00_00535D48(&p, &n, arg1, (s32)remain)) goto fail;
    *pp = p;
    return cons | n;
fail:
    func_L00_004F84C8(0xD, 0x6B, 0x78, 0, 0);
    return 0x80;
}
