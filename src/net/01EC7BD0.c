/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern s32 func_01EA9828(u8 *arg0, s32 arg1);
extern s32 func_01EC3460(void);
extern s32 func_01EC3498(void);
extern s32 func_01EC5280(s32 a0);
extern s32 func_01EC5618(s32, s32, s32, void *, s32, s32);

s32 func_01EC7BD0(s32 a0, s32 a1, u32 a2, u8 *a3, s32 a4)
{
    s32 r = func_01EC3460();
    s32 ret;
    s32 s;
    s32 p;
    u8 buf[0x90];
    u8 n;
    s32 hdr;
    s32 total;
    u8 *dst;

    if (r != 0) {
        ret = r;
    } else {
        s = 2;
        p = func_01EC5280(a0);
        if (p != 0) {
            n = (((u32)a2 - (u32)a1) >> 3) + 1;
            hdr = n | 0x80;
            buf[0] = a4;
            if (a1 == 0)
                hdr = n;
            buf[1] = hdr;
            total = 2;
            dst = buf + 2;
            if (a1 != 0) {
                func_01EA9828(dst, a1 & 0xFFFF);
                dst = buf + 4;
                total = 4;
            }
            func_0011A370(dst, a3, n);
            total += n;
            s = func_01EC5618(*(s32 *)(p + 0x9C), 0x29, 0xFFFF, buf, total, 0);
        }
        func_01EC3498();
        ret = s;
    }
    return ret;
}
