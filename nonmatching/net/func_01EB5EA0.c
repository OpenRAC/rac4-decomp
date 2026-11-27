/* Not matching yet: BYTES 1/268 (tools/try_func.py func_01EB5EA0 --diff). Not part of the build. */
/* cflags: @ee296 -O3 -G0 */
#include "common.h"

extern s32 D_00169508;
extern char D_001B26C0[];
extern char D_001B2700[];
extern void func_0011A518(void *, s32, s32);
extern s32 func_01E9BF20(void *, void *, void *, s32);
extern s32 func_01EB4D80(u8 *);

s32 func_01EB5EA0(s32 *arg0, s32 arg1, s32 *arg2) {
    u8 buf[0x30];
    s32 n;
    s32 i;

    if (D_00169508 < 0) {
        return 0xC350;
    }
    if (arg0 == 0) {
        return 2;
    }
    if (arg2 == 0) {
        return 2;
    }
    func_0011A518(buf, 0, 0x30);
    func_0011A518(arg0, 0, arg1 * 8);
    *arg2 = 0;
    n = func_01E9BF20(D_001B26C0, D_001B2700, buf, 3);
    if (n < 0) {
        return 0xC350;
    }
    i = 0;
    while (i < arg1 && i < n) {
        arg0[i * 2] = func_01EB4D80(buf + i * 16);
        i++;
        (*arg2)++;
    }
    return 0;
}
