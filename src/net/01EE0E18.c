/* cflags: @ee296 -O2 -G0 */
#include "common.h"
/* Not matching yet: BYTES 6/44 (tools/try_func.py func_01EE0E18 --diff). Not part of the build. */
extern void func_01EE0C28(s32, s32, void *, s32);

/* Stores two bytes into a local buffer and calls func_01EE0C28 with a 0x15 code and the buffer length 2. */
void func_01EE0E18(s32 arg0, s32 arg1, s32 arg2) {
    s8 buf[2];

    buf[0] = arg1;
    buf[1] = arg2;
    func_01EE0C28(arg0, 0x15, buf, 2);
}
