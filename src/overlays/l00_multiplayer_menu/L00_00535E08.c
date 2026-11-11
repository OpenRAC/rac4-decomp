/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004F9FF8 (src/levels/39_multiplayer_menu/L39_004F9FF8.c, GPL-3.0), the same code in both games. */

extern void func_L00_00535F10(u8 **pp, s32 length);
void func_L00_00535E08(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass) {
    u8 *p = *pp;
    s32 i;
    i = (constructed) ? 0x20 : 0;
    i |= (xclass & 0xC0);
    if (tag < 31) {
        *(p++) = i | (tag & 0x1F);
    } else {
        *(p++) = i | 0x1F;
        while (tag > 0x7F) {
            *(p++) = (tag & 0x7F) | 0x80;
            tag >>= 7;
        }
        *(p++) = (tag & 0x7F);
    }
    if (constructed == 2 && length == 0) {
        *(p++) = 0x80;
    } else {
        func_L00_00535F10(&p, length);
    }
    *pp = p;
}
