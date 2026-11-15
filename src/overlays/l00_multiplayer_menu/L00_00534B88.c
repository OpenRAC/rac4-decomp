/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00535E08(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass);
extern s32 func_L00_00535FB0(s32 arg0, s32 arg1, s32 arg2);

/* writes a one-byte tagged value to the output pointer and returns its encoded length */
s32 func_L00_00534B88(s32 a, u8 **pp) {
    u8 *p;
    s32 r;
    r = func_L00_00535FB0(0, 1, 1);
    if (pp == 0) {
        return r;
    }
    p = *pp;
    func_L00_00535E08(&p, 0, 1, 1, 0);
    *(p++) = (u8)a;
    *pp = p;
    return r;
}
