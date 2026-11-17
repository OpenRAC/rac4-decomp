/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_0011A370(void *, void *, s32);
void func_01EFC7B4(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    u8 buf[0x80];
    u32 n = arg2 - arg1;
    if (n < 0x80) {
        func_0011A518(buf, 0, 0x80);
        func_0011A370(buf, arg3 + arg1, n);
    }
}
