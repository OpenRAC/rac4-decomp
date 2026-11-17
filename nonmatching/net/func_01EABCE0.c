/* Not matching yet: BYTES 4/188 (tools/try_func.py func_01EABCE0 --diff) (tools/try_func.py func_01EABCE0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00168BAC[];
extern s32 D_001B2420[];

void func_01EABDA0(void *, s32);
void func_01EABC10(void *);
void func_01EABCD0(s32);

s32 func_01EABCE0(u32 a0, s32 a1) {
    s32 buf[4];
    s32 s0;
    s32 s1;

    if (D_00168BAC[0] == 0) {
        return 1;
    }
    s0 = D_001B2420[0x65];
    s1 = a0 >> 1;
    D_001B2420[s0] = s1;
    if ((u32)D_001B2420[0x64] < 0x64) {
        D_001B2420[0x64] = D_001B2420[0x64] + 1;
    }
    s0 = s0 + 1;
    func_01EABDA0(buf, a1);
    func_01EABC10(&buf[1]);
    if (buf[0] >= s1) {
        func_01EABCD0(a1 + s1);
    }
    if (s0 >= 0x64) {
        s0 = 0;
    }
    D_001B2420[0x65] = s0;
    return 0;
}
