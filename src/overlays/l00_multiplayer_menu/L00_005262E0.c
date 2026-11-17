/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_005208E8(s32, s32, s32, s32, void *, s32);

/* Looks up a 0x10 entry by key and reports its 0xC and 0x10 fields. */
s32 func_L00_005262E0(void *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    u8 *entry;

    func_L00_005208E8(*(s32 *)((u8 *)arg0 + 4), 0x10, arg1, 0, &entry, 0);
    if (entry != 0) {
        if (arg2 != 0) {
            *arg2 = *(s32 *)(entry + 0xC);
        }
        if (arg3 != 0) {
            *arg3 = *(s32 *)(entry + 0x10);
        }
        return 0;
    }
    if (arg2 != 0) {
        *arg2 = 0;
    }
    if (arg3 != 0) {
        *arg3 = 0;
    }
    return 0;
}
