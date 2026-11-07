/* Not matching yet: BYTES 21/88 (tools/try_func.py func_004F2268 --diff). Not part of the build. (tools/try_func.py func_004F2268 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns2 */
#include "common.h"

// Initialise the descriptor and clear its entry list.
void func_004F2268(u8 *p, s32 arg1, s32 arg2, s32 count) {
    s32 i;

    *(s32 *)(p + 0xC) = 0;
    *(s32 *)(p + 0x0) = arg1;
    *(s32 *)(p + 0x4) = arg2;
    *(s32 *)(p + 0x10) = count;
    *(s32 *)(p + 0x8) = 0;
    for (i = 0; i < count; i++) {
        *(s32 *)(*(u8 **)(p + 0x4) + i * 0x27E40) = 0;
        *(s32 *)(*(u8 **)(p + 0x4) + i * 0x27E40 + 0x4) = i;
    }
}
