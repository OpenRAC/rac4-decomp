/* Not matching yet: SIZE ours 204 / retail 200 (tools/try_func.py func_01EFD0E4 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad[0x14];
    f32 (*f14)(void *, void *, void *, s32);
} Type1;

extern s32 func_0011AB04(void *);
extern s32 func_01EFCEE8(s32, s32);

s32 func_01EFD0E4(s32 arg0, s32 arg1, Type1 **arg2, f32 dist) {
    s32 len = func_0011AB04((void *)arg0);
    s32 prev = len;
    s32 n = 0;

    if (dist < (*arg2)->f14(arg2, (void *)arg1, (void *)arg0, len)) {
        do {
            prev = func_01EFCEE8(arg0, prev);
            n++;
        } while (dist < (*arg2)->f14(arg2, (void *)arg1, (void *)arg0, len));
    }
    return len - n;
}
