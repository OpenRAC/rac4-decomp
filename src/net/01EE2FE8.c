/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011EAA0(char *file, s32 line, char *expr);
extern s32 func_01EAE830(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern char D_0019A9A0[];
extern char D_0019AD18[];

/* Checks that arg2 matches the word at offset 0x20 (asserting otherwise), then calls func_01EAE830 and returns arg2; returns 0 on mismatch. */
s32 func_01EE2FE8(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 ret;

    ret = 0;
    if (arg2 != *(s32 *)(arg0 + 0x20)) {
        func_0011EAA0(D_0019A9A0, 0x611, D_0019AD18);
        ret = 0;
        if (arg2 != *(s32 *)(arg0 + 0x20)) {
            return ret;
        }
    }
    func_01EAE830((s32)arg0 - *(s32 *)(arg0 + 0x20) + 0x208, *(s32 *)(arg0 + 0x20), *(s32 *)(arg0 + 0x24), arg1, arg2);
    return arg2;
}
