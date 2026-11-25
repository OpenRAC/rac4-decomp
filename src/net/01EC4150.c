/* cflags: @ee32-040921 -O2 -G8 */
#include "common.h"
extern s32 func_01EA9828(u8 *arg0, s32 arg1);
extern s32 func_01EC3460();
extern s32 func_01EC3498();
extern s32 func_01EC5280(s32 a0);
extern s32 func_01EC5618(s32, s32, s32, void *, s32, s32);
s32 func_01EC4150(s32 a0, s32 a1)
{
    s32 r = func_01EC3460();
    s32 s;
    s32 p;
    u8 buf[0x10];
    if (r != 0) {
        return r;
    }
    s = 2;
    p = func_01EC5280(a0);
    if (p != 0) {
        func_01EA9828(buf, a1 & 0xFFFF);
        s = func_01EC5618(*(s32 *)(p + 0x9C), 0xE, 0xFFFF, buf, 2, 0x40);
    }
    func_01EC3498();
    return s;
}
