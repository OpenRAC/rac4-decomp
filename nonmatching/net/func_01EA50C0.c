/* Not matching yet: BYTES 51/156 (tools/try_func.py func_01EA50C0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);

void func_01EA50C0(s32 arg0, u8 *arg1) {
    s32 sp[5];
    s32 code;

    if (arg1 != NULL && *(s32 *)(arg1 + 0x468) == 2 && *(s32 *)(arg1 + 0x430) != 0) {
        func_0011A518(sp, 0, 0x14);
        sp[1] = 4;
        sp[2] = 1;
        sp[0] = (s32)arg1;
        *(s32 *)(arg1 + 0x454) = 4;
        switch (arg0) {
        case 0xD4E9:
            code = 0xE;
            break;
        default:
            code = 0x25;
            break;
        }
        sp[3] = code;
        sp[4] = *(s32 *)(arg1 + 0x434);
        ((void (*)(void *, s32))*(s32 *)(arg1 + 0x430))(sp, 0xD4E9);
    }
}
