/* Not matching yet: BYTES 83/148 (tools/try_func.py func_01EF5548 --diff) (tools/try_func.py func_01EF5548 --diff). Not part of the build. */
/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

s32 func_01EA7538(void);
s32 func_01EA7EC8(s32, s32 *);
void func_01EED528(s32, s32);
void func_01F0C090(void *, s32);
extern u8 D_0019C8C0[];

s32 func_01EF5548(void *arg0) {
    s32 local;
    s32 r;

    if (func_01EA7538() == 0) {
        r = func_01EA7EC8(*(s32 *)((char *)arg0 + 0xC), &local);
        if (local == 1 && r == 0)
            return 1;
        if (local == 0 && r == 0)
            return 0;
        if (r != 0) {
            func_01EED528(0x26, local);
        } else {
            func_01EED528(0x26, local);
            func_01F0C090(D_0019C8C0, 0x1CA);
        }
    }
    return 0;
}
